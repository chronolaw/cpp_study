// Copyright (c) 2020 by Chrono
//
// g++ luajit.cpp -std=c++11 -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -o a.out;./a.out
//
// g++ luajit.cpp -std=c++11 -I/usr/local/include/luajit-2.1 /usr/local/lib/libluajit-5.1.a -ldl -o a.out;./a.out
// g++ luajit.cpp -std=c++11 -I/usr/local/include/luajit-2.1 -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lluajit-5.1 -ldl -o a.out;./a.out
//

#include <cassert>
#include <iostream>

extern "C" {
#include <luajit.h>
#include <lualib.h>
#include <lauxlib.h>
}

void case1()
{
    auto L = luaL_newstate();
    assert(L);

    luaL_openlibs(L);

    lua_close(L);
}

int main()
{
    using namespace std;

    cout << "luajit demo" << endl;
}
