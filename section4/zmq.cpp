// Copyright (c) 2020 by Chrono
//
// g++ zmq.cpp -std=c++14 -lzmq -o a.out;./a.out

#include <iostream>

#include <string>
#include <vector>

#include <zmq.hpp>

using namespace std;


void case1()
{
    //using namespace std::literals::string_literals;

    const auto thread_num = 1;
    const auto addr = "ipc:///dev/shm/zmq.sock"s;

    zmq::context_t context(thread_num);

    auto make_sock = [&](auto mode)
    {
        return zmq::socket_t(context, mode);
    };

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
    auto srv = [=]()
    {
    };

    auto client = [=]()
    {
    };

}

int main()
{
    case1();

    cout << "zmq demo" << endl;
}
