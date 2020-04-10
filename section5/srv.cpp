// Copyright (c) 2020 by Chrono
//
// g++ srv.cpp -std=c++14 -I../common -I../common/include -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -lzmq -lpthread -o a.out;./a.out
// g++ srv.cpp -std=c++14 -I../common -I../common/include -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -lzmq -lpthread -g -O0 -o a.out
// g++ srv.cpp -std=c++14 -I../common -I../common/include -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -lzmq -lpthread -g -O0 -o a.out;./a.out

//#include <iostream>

#include "cpplang.hpp"
#include "Summary.hpp"
#include "Zmq.hpp"
#include "Config.hpp"

// you should put json.hpp in ../common
#include "json.hpp"

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
{
    cout << "hello cpp_study server" << endl;

    Summary sum;
    std::atomic_int count {0};

    // todo: try-catch
    auto cycle = [&](const auto& addr)
    {
        using zmq_ctx = ZmqContext<1>;

        // zmq recv

        auto sock = zmq_ctx::recv_sock();

        sock.bind(addr);
        assert(sock.connected());

        for(;;) {

            // shared_ptr/unique_ptr
            auto msg_ptr = std::make_shared<zmq_message_type>();

            sock.recv(msg_ptr.get());
            //cout << msg_ptr->size() << endl;

            // async process msg

            // todo: try-catch
            std::async(std::launch::async,
            [&sum, &count](decltype(msg_ptr) ptr)
            {
                //cout << ptr.unique() << endl;

                SalesData book;

                auto obj = msgpack::unpack(
                            ptr->data<char>(), ptr->size()).get();
                obj.convert(book);

                //cout << book.id() << endl;
                //debug_print(book);

                sum.add_sales(book);

                ++count;
                cout << count << endl;
            },
            msg_ptr);
        }
    };

    auto fu = std::async(cycle, "tcp://127.0.0.1:5555");

    fu.wait();
}
