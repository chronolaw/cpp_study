// Copyright (c) 2020 by Chrono
//
// https://github.com/whoshuu/cpr/
// cmake . -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
// make && make install
//
// g++ cpr.cpp -std=c++11 -lcpr -lpthread -lcurl -o a.out;./a.out
// g++ cpr.cpp -std=c++14 -lcpr -lpthread -lcurl -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <cpr/cpr.h>

using namespace std;

void case1()
{
    auto res = cpr::Get(
                cpr::Url{"http://nginx.org"}
    );

    cout << res.elapsed << endl;

    cout << res.url << endl;
    cout << res.status_code << endl;
    //cout << res.header["server"] << endl;
    cout << res.text.length() << endl;

    for(auto& x : res.header) {
        cout << x.first << "=>"
             << x.second << endl;
    }
    cout << endl;
}

void case2()
{
    auto res1 = cpr::Head(
                cpr::Url{"http://nginx.org/"}
    );
    assert(res1.text.empty());

#if 0
    auto res2 = cpr::Get(
                cpr::Url{"http://nginx.org"},
                cpr::Parameters{
                    {"a", 1}, {"b", 2}}
    );
#endif

    auto res3 = cpr::Post(
                cpr::Url{"http://nginx.org"},
                cpr::Header{{"x", "xxx"}},
                cpr::Body{"post data"},
                cpr::Timeout{200ms}
    );
}

void case3()
{
    auto f = cpr::GetAsync(
                cpr::Url{"http://openresty.org"}
    );

    auto res = f.get();

    cout << res.elapsed << endl;

    for(auto& x : res.header) {
        cout << x.first << "=>"
             << x.second << endl;
    }
}

int main()
{
    case1();
    case2();
    case3();

    cout << "libcpr demo" << endl;
}
