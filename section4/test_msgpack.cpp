// Copyright (c) 2020 by Chrono
//
// g++ test_msgpack.cpp -std=c++11 -lmsgpackc -o a.out;./a.out
// g++ test_msgpack.cpp -std=c++14 -lmsgpackc -o a.out;./a.out

#include <iostream>

#include <msgpack/pack.hpp>
#include <msgpack/unpack.hpp>

int main()
{
    using namespace std;

    cout << "msgpack demo" << endl;
}
