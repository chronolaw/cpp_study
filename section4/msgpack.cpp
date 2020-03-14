// Copyright (c) 2020 by Chrono
//
// sudo apt-get install libmsgpack-dev
//
// /usr/include/msgpack
// g++ msgpack.cpp -std=c++11 -lmsgpackc -o a.out;./a.out
// g++ msgpack.cpp -std=c++14 -lmsgpackc -o a.out;./a.out

#include <iostream>

#include <msgpack.hpp>

void case1()
{
    //msgpack::type::tuple<>
}

int main()
{
    using namespace std;

    cout << "msgpack demo" << endl;
}
