// Copyright (c) 2020 by Chrono
//
// g++ lua_shared.cpp -std=c++11 -shared -fPIC -o liblua_shared.so
// g++ lua_shared.cpp -std=c++14 -shared -fPIC -o liblua_shared.so

//#include <luajit-2.1/luajit.h>

extern "C" {

int num = 10;
int my_add(int a, int b);

}

int my_add(int a, int b)
{
    return a + b;
}
