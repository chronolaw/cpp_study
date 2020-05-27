// Copyright (c) 2020 by Chrono
//
// g++ test.cpp -std=c++11 -o a.out;./a.out
// g++ test.cpp -std=c++14 -o a.out;./a.out
// g++ test.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

//#include "std.hpp"

int main()
{
    using namespace std;

    cout << "c++ version = " << __cplusplus << endl;

    cout << "gcc version = " << __VERSION__ << endl;

    cout << "gcc major = " << __GNUC__ << endl;
    cout << "gcc minor = " << __GNUC_MINOR__ << endl;
    cout << "gcc patch = " << __GNUC_PATCHLEVEL__ << endl;

    // check __GLIBCXX__ for macos
#ifndef __GLIBCXX__
#   define __GLIBCXX__ "unkown version,please check or config your gcc path,or your OS not surpport."
#endif

    cout << "libstdc++ = " << __GLIBCXX__ << endl;
}
