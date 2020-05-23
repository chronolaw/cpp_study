// Copyright (c) 2020 by Chrono
//
// g++ srv.cpp -std=c++14 -I../common -I../common/include -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -lzmq -lpthread -lcpr -lcurl -o a.out;./a.out
// g++ srv.cpp -std=c++14 -I../common -I../common/include -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -lzmq -lpthread -lcpr -lcurl -g -O0 -o a.out
// g++ srv.cpp -std=c++14 -I../common -I../common/include -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -lzmq -lpthread -lcpr -lcurl -g -O0 -o a.out;./a.out

//#include <iostream>

#include "cpplang.hpp"
#include "Summary.hpp"
#include "Zmq.hpp"
#include "Config.hpp"

// you should put json.hpp in ../common
#include "json.hpp"

#include <cstdio>
#include <cpr/cpr.h>

USING_NAMESPACE(std);
USING_NAMESPACE(cpp_study);

static
auto debug_print = [](auto& b)
{
    using json_t = nlohmann::json;

    json_t j;

    j["id"] = b.id();
    j["sold"] = b.sold();
    j["revenue"] = b.revenue();
    //j["average"] = b.average();

    std::cout << j.dump(2) << std::endl;
};

int main()
try
{
    cout << "hello cpp_study server" << endl;

    Config conf;
    conf.load("./conf.lua");

    Summary sum;
    std::atomic_int count {0};

    // todo: try-catch
    auto recv_cycle = [&]()
    {
        using zmq_ctx = ZmqContext<1>;

        // zmq recv

        auto sock = zmq_ctx::recv_sock();

        sock.bind(conf.get<string>("config.zmq_ipc_addr"));
        assert(sock.connected());

        for(;;) {

            // xxx : shared_ptr/unique_ptr
            auto msg_ptr = std::make_shared<zmq_message_type>();

            sock.recv(msg_ptr.get());
            //cout << msg_ptr->size() << endl;

            ++count;
            cout << count << endl;
            //printf("count = %d\n", static_cast<int>(count));

            // async process msg

            // todo: try-catch
            //auto f = std::async(std::launch::async,
            std::thread(
            [&sum, msg_ptr]()
            //[&sum, &count](decltype(msg_ptr) ptr)
            {
                //cout << ptr.unique() << endl;

                SalesData book;

                // xxx: json/msgpack/protobuf
                auto obj = msgpack::unpack(
                            msg_ptr->data<char>(), msg_ptr->size()).get();
                obj.convert(book);

                //cout << book.id() << endl;
                //debug_print(book);

                sum.add_sales(book);
            }).detach();   // async
        }   // for(;;)
    };  // recv_cycle lambda

    auto log_cycle = [&]()
    {
        auto http_addr = conf.get<string>("config.http_addr");
        auto time_interval = conf.get<int>("config.time_interval");

        for(;;) {
            std::this_thread::sleep_for(time_interval * 1s);
            //cout << "log_cycle" << endl;

            //auto info = sum.minmax_sales();
            //cout << "log_cycle get info" << endl;

            using json_t = nlohmann::json;

            json_t j;

            j["count"] = static_cast<int>(count);
            j["minmax"] = sum.minmax_sales();//{info.first, info.second};

            auto res = cpr::Post(
                       cpr::Url{http_addr},
                       cpr::Body{j.dump()},
                       cpr::Timeout{200ms}
            );

            if (res.status_code != 200) {
                cerr << "http post failed" << endl;
                //printf("http post failed\n");
            }
        }   // for(;;)
    };  // log_cycle lambda

    // launch log_cycle
    auto fu1 = std::async(std::launch::async, log_cycle);

    // launch recv_cycle then wait
    auto fu2 = std::async(std::launch::async, recv_cycle);

    fu2.wait();
}
catch(std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
