// Copyright (c) 2020 by Chrono
//
// https://github.com/whoshuu/cpr/
// cmake . -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
// make && make install
//
// g++ cpr.cpp -std=c++11 -lcpr -lcurl -o a.out;./a.out
// g++ cpr.cpp -std=c++14 -lcpr -lcurl -o a.out;./a.out

#include <iostream>

#include <cpr/cpr.h>

using namespace std;

void case1()
{
    auto resp = cpr::Get(
                cpr::Url{"http://nginx.org"},
                cpr::Parameters{{"key", "value"}}
    );

    cout << resp.url << endl;
    cout << resp.status_code << endl;
    cout << resp.header["server"] << endl;
    cout << resp.text.length() << endl;

    for(auto& x : resp.header) {
        cout << x.first << "=>"
             << x.second << endl;
    }
}

int main()
{
    case1();

    cout << "libcpr demo" << endl;
}
