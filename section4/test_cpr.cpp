// Copyright (c) 2020 by Chrono
//
// https://github.com/whoshuu/cpr/
// cmake . -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
// make && make install
//
// g++ test_cpr.cpp -std=c++11 -lcpr -lcurl -o a.out;./a.out
// g++ test_cpr.cpp -std=c++14 -lcpr -lcurl -o a.out;./a.out

#include <iostream>

#include <cpr/cpr.h>

int main()
{
    using namespace std;

    cout << "libcpr demo" << endl;
}
