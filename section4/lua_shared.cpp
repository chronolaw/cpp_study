// Copyright (c) 2020 by Chrono
//
// g++ lua_shared.cpp -std=c++11 -shared -fPIC -o lua_shared.so
// g++ lua_shared.cpp -std=c++14 

#include <luajit-2.1/luajit.h>

extern "C" {

int my_add(int a, int b);

}

int my_add(int a, int b)
{
    return a + b;
}
