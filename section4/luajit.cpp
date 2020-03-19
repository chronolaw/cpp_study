// Copyright (c) 2020 by Chrono
//
// g++ luajit.cpp -std=c++11 -I../common -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -o a.out;./a.out
// g++ luajit.cpp -std=c++11 -I../common -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -O0 -g -o a.out
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

#include <LuaBridge/LuaBridge.h>
//namespace lua = luabridge;
using namespace luabridge;

using namespace std;

class LuaState final
{
public:
    using lua_state_t = decltype(luaL_newstate());
private:
    lua_state_t L = nullptr;
public:
    LuaState()
    {
        L = luaL_newstate();
    }

   ~LuaState()
    {
        lua_close(L);
    }
public:
    operator lua_state_t() const
    {
        return L;
    }
};

void case1()
{
    auto L = luaL_newstate();
    assert(L);

    luaL_openlibs(L);

    auto package = getGlobal(L, "package");

    auto path = package["path"];

    cout << path << endl;

    lua_close(L);
}

int main()
{
    case1();

    cout << "luajit demo" << endl;
}
