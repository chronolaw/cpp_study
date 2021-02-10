// Copyright (c) 2020 by Chrono
//
// docker pull quay.io/coreos/etcd
// docker pull quay.io/coreos/etcd:v3.3.25
//
// https://etcd.io/docs/v2/api/
//
// docker-compose -f etcd.yml -p etcd up -d
// docker-compose -f etcd.yml -p etcd down
//
// curl 127.0.0.1:2379/version
// {"etcdserver":"3.3.8","etcdcluster":"3.3.0"}
// {"etcdserver":"3.3.25","etcdcluster":"3.3.0"}
//
// curl http://127.0.0.1:2379/v2/keys/foo -XPUT -d value="Hello xxx"
// curl http://127.0.0.1:2379/v2/keys/foo

#ifndef _UTILITY_ETCD_HPP_
#define _UTILITY_ETCD_HPP_

#include <utility/curl.hpp>
#include <utility/fmt.hpp>
#include <utility/json.hpp>

namespace etcd::v2 {

// sample output
// Version:
// {
//   "etcdcluster": "3.3.0",
//   "etcdserver": "3.3.8",
//   "statusCode": 200
// }
// Get:
// {
//   "action": "get",
//   "node": {
//     "createdIndex": 29,
//     "key": "/test/xxx",
//     "modifiedIndex": 29,
//     "value": "etcd"
//   },
//   "statusCode": 200
// }
class Client final {
public:
    using string_type = std::string;
    using string_ref_type = const std::string&;

    using json_type = nlohmann::json;
public:
    Client(string_ref_type addr, int port) noexcept {

        m_url = fmt::format("http://{}:{}", addr, port);
        //m_url = "http://" + addr + std::to_string(port);

        m_prefix = m_url + "/v2/keys";
    }

   ~Client() noexcept = default;
public:
    json_type Version() noexcept {

        auto res = cpr::Get(
                m_url + "/version"
                );

        return wrap_reply(res);
    }

    // statusCode=2xx => OK
    json_type Set(string_ref_type key,
                  string_ref_type value) noexcept {

        auto res = cpr::Put(
            m_prefix + key,
            cpr::Body("value=" + value)
        );

        return wrap_reply(res);
    }

    // statusCode=200 => OK
    json_type Get(string_ref_type key) noexcept {

        auto res = cpr::Get(
            m_prefix + key
        );

        return wrap_reply(res);
    }

    // statusCode=200 => OK
    json_type Delete(string_ref_type key) noexcept {

        auto res = cpr::Delete(
            m_prefix + key
        );

        return wrap_reply(res);
    }

public:
    // statusCode=2xx => OK
    json_type Set(string_ref_type key,
                  string_ref_type value, int ttl) noexcept {

        auto res = cpr::Put(
            m_prefix + key,
            cpr::Body(fmt::format("value={};ttl={}", value, ttl))
        );

        return wrap_reply(res);
    }

public:
    // It will block the thread until event happens
    json_type Watch(string_ref_type key) noexcept {

        auto watch_url = m_prefix + key + "?wait=true";

        // waiting for event
        auto res = cpr::Get(watch_url);

        // fatal error
        if (res.error.code != cpr::ErrorCode::OK) {

            return json_type {
                {"error", res.error.message}
                };
        }

        // http ok but timed out
        if (res.text.empty()) {

            return json_type {
                {"error", "timedout"}
                };
        }

        return wrap_reply(res);
    }

private:
    template<typename T>
    json_type wrap_reply(const T& res) noexcept {

        //std::cout << res.status_code << std::endl;

        //json_type j;
        //j["code"] = res.status_code;
        //j["value"] = json_type::parse(res.text);

        if (res.error.code != cpr::ErrorCode::OK) {

            return json_type {
                //{"status_code", res.error.code},
                {"error", res.error.message}
                };
        }

        auto j = json_type::parse(res.text);
        j["statusCode"] = res.status_code;

        return j;
    }
private:
    string_type m_url;
    string_type m_prefix;
};

}   // namespace etcd::v2

#endif  //_UTILITY_ETCD_HPP_

