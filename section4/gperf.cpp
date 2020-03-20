// Copyright (c) 2020 by Chrono
//
// g++ gperf.cpp -std=c++11 -lprofiler -ltcmalloc -o a.out;./a.out
// g++ gperf.cpp -std=c++14 -lprofiler -ltcmalloc -o a.out;./a.out

#include <iostream>

#include <gperftools/profiler.h>
#include <gperftools/heap-profiler.h>

using namespace std;


int main()
{
    cout << "gperf demo" << endl;
}
