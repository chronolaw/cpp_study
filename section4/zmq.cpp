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

    //zmq::socket_t sock1(context, ZMQ_PUSH);
    auto sock1 = make_sock(ZMQ_PUSH);

    sock1.connect(addr);

    auto str = "hello zmq"s;

    sock1.send(begin(str), end(str));

    auto sock2 = make_sock(ZMQ_PULL);

    sock2.bind(addr);

    zmq::message_t msg;

    sock2.recv(&msg);

    cout << msg.size() << endl;

    string s = {msg.data<char>(), msg.size()};
    cout << s << endl;
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
