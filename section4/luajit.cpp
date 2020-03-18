// Copyright (c) 2020 by Chrono
//
// g++ luajit.cpp -std=c++11 -o a.out;./a.out
// g++ luajit.cpp -std=c++14 -o a.out;./a.out
// g++ luajit.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

#include <luajit-2.1/luajit.h>

int main()
{
    using namespace std;

    cout << "luajit demo" << endl;
}
