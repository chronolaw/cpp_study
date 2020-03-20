// Copyright (c) 2020 by Chrono
//
// git clone git@github.com:openresty/luajit2.git
// make && make install
//
// git clone git@github.com:vinniefalco/LuaBridge.git
//
// g++ luajit.cpp -std=c++11 -I../common -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -o a.out;./a.out
// g++ luajit.cpp -std=c++11 -I../common -I/usr/local/include/luajit-2.1 -lluajit-5.1 -ldl -O0 -g -o a.out
//
// g++ luajit.cpp -std=c++11 -I/usr/local/include/luajit-2.1 /usr/local/lib/libluajit-5.1.a -ldl -o a.out;./a.out
// g++ luajit.cpp -std=c++11 -I/usr/local/include/luajit-2.1 -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lluajit-5.1 -ldl -o a.out;./a.out
//

#include <cassert>
#include <iostream>
#include <memory>

extern "C" {
#include <luajit.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <LuaBridge/LuaBridge.h>
//namespace lua = luabridge;
using namespace luabridge;

using namespace std;

#if 0
class MyLuaState final
{
public:
    using lua_state_t = decltype(luaL_newstate());
private:
    lua_state_t L = nullptr;
public:
    MyLuaState()
    {
        L = luaL_newstate();
        assert(L);

        luaL_openlibs(L);
    }

   ~MyLuaState()
    {
        lua_close(L);
    }
public:
    operator lua_state_t() const
    {
        return L;
    }

    int dofile(const char* filename) const
    {
        return luaL_dofile(L, filename);
    }
public:
    MyLuaState(const MyLuaState&) = delete;
    MyLuaState& operator=(const MyLuaState&) = delete;
};
#endif

//using MyLuaState = std::shared_ptr<lua_State>;
auto make_luavm = []()
{
    std::shared_ptr<lua_State> vm(
        luaL_newstate(), lua_close
        );
    assert(vm);

    luaL_openlibs(vm.get());

    return vm;
};

#define L vm.get()

void case1()
{
    //MyLuaState L;
    auto vm = make_luavm();

    auto package = getGlobal(L, "package");

    string path = package["path"];
    string cpath = package["cpath"];

    cout << path << endl;
    cout << cpath << endl;
}

void case2()
{
    //MyLuaState L;
    auto vm = make_luavm();

    int status;

    status = luaL_dostring(L, "print('hello lua')");
    status = luaL_dofile(L, "./embedded.lua");
    status = luaL_dofile(L, "./shared.lua");

    //L.dofile("./embedded.lua");
}

void case3()
{
    //MyLuaState L;
    auto vm = make_luavm();

    int status;
    string chunk = R"(
        function say(s)
            print(s)
        end
        function add(a, b)
            return a + b
        end
    )";

    status = luaL_dostring(L, chunk.c_str());
    assert(status == 0);

    auto f1 = getGlobal(L, "say");
    f1("say something");

    auto f2 = getGlobal(L, "add");
    auto v = f2(10, 20);
    assert(v == 30);
    //cout << v << endl;

    //L.dofile("./embedded.lua");
}

int main()
{
    case1();
    case2();
    case3();

    cout << "luajit demo" << endl;
}
