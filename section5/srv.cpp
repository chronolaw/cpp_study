// Copyright (c) 2020 by Chrono
//
// g++ srv.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -o a.out;./a.out
// g++ srv.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -g -O0 -o a.out
// g++ srv.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -g -O0 -o a.out;./a.out

//#include <iostream>

#include "cpplang.hpp"
#include "Summary.hpp"
#include "Zmq.hpp"

// you should put json.hpp in ../common
#include "json.hpp"

USING_NAMESPACE(std);
USING_NAMESPACE(cpp_study);

int main()
{
    cout << "hello cpp_study server" << endl;

    Summary sum;

    auto cycle = [&](const auto& addr)
    {
        using zmq_ctx = ZmqContext<1>;

        auto sock = zmq_ctx::recv_sock();

        sock.bind(addr);
        assert(sock.connected());

        auto msg_ptr = std::make_shared<zmq_message_type>();

        sock.recv(msg_ptr.get());
        cout << msg_ptr->size() << endl;

        std::async(
        [&sum, msg_ptr]()
        {
            SalesData data;

            auto obj = msgpack::unpack(
                        msg_ptr->data<char>(), msg_ptr->size()).get();
            obj.convert(data);

            sum.add_sales(data);
        });
    };

    auto fu = std::async(cycle, "tcp://127.0.0.1:5555");

    fu.wait();
}
