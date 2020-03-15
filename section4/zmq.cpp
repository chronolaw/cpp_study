// Copyright (c) 2020 by Chrono
//
// g++ zmq.cpp -std=c++14 -lzmq -lpthread -o a.out;./a.out

#include <iostream>

#include <string>
#include <vector>
#include <future>

#include <zmq.hpp>

using namespace std;

const auto thread_num = 1;

zmq::context_t context(thread_num);

auto make_sock = [&](auto mode)
{
    return zmq::socket_t(context, mode);
};

void case1()
{
    const auto addr = "ipc:///dev/shm/zmq.sock"s;

    auto receiver = [=]()
    {
        auto sock = make_sock(ZMQ_PULL);

        sock.bind(addr);
        assert(sock.connected());

        zmq::message_t msg;

        sock.recv(&msg);

        cout << msg.size() << endl;

        string s = {msg.data<char>(), msg.size()};
        cout << s << endl;
    };

    auto sender = [=]()
    {
        auto sock = make_sock(ZMQ_PUSH);

        sock.connect(addr);
        assert(sock.connected());

        string s = "hello zmq";
        //zmq::message_t msg(begin(s), end(s));
        //sock.send(msg);

        sock.send(begin(s), end(s));
    };

    sender();
    receiver();
}

void case2()
{
    const auto addr = "tcp://127.0.0.1:5555"s;

    auto srv = [=]()
    {
        auto sock = make_sock(ZMQ_PULL);

        sock.bind(addr);
        assert(sock.connected());

        zmq::message_t msg;

        for(int i = 0; i < 4; i++) {
            sock.recv(&msg);

            string s = {msg.data<char>(), msg.size()};
            cout << s << endl;
        }
    };

    auto client = [=](int i)
    {
        auto sock = make_sock(ZMQ_PUSH);

        sock.connect(addr);
        assert(sock.connected());

        string s = "zmq msg " + to_string(i);
        //zmq::message_t msg(begin(s), end(s));
        //sock.send(msg);

        sock.send(begin(s), end(s));
    };

    auto f = std::async(srv);

    for(int i = 0; i < 4; i++) {
        client(i);
    }

    f.wait();
}

int main()
{
    case1();
    case2();

    cout << "zmq demo" << endl;
}
