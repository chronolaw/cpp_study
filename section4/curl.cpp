// Copyright (c) 2020 by Chrono
//
// sudo apt-get remove libcurl4
// sudo apt-get install libcurl4-openssl-dev
//
// curl-config --libs
// curl-config --version
// curl-config --features
// curl-config --protocols
//
// g++ curl.cpp -std=c++11 -lcurl -o a.out;./a.out
// g++ curl.cpp -std=c++14 -lcurl -o a.out;./a.out

#include <iostream>

#include <curl/curl.h>

int main()
{
    using namespace std;

    cout << "libcurl demo" << endl;
}
