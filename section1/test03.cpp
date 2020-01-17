// Copyright (c) 2020 by Chrono
//
// g++ test03.cpp -std=c++98 -o a.out;./a.out
// g++ test03.cpp -std=c++11 -o a.out;./a.out
// g++ test03.cpp -std=c++14 -o a.out;./a.out
//
// g++ test03.cpp -DNDEBUG -std=c++11 -o a.out;./a.out
//
// gcc -E -dM - < /dev/null

#include <iostream>

void case1()
{
    using namespace std;

#if __cplusplus >= 201402
    cout << "c++14 or later" << endl;
#elif __cplusplus >= 201103
    cout << "c++11 or before" << endl;
#else   // __cplusplus < 201103
#   error "c++ is too old"
#endif  // __cplusplus >= 201402

#if __GNUC__ <= 4
    cout << "gcc is too old" << endl;
#else   // __GNUC__ > 4
    cout << "gcc is good enough" << endl;
#endif  // __GNUC__ <= 4

#if defined(__SSE4_2__) && defined(__x86_64)
    cout << "we can do more optimization" << endl;
#endif  // defined(__SSE4_2__) && defined(__x86_64)

#if __linux__
    cout << "running on linux" << endl;
#else   // not linux
    cout << "running on others" << endl;
#endif  //__linux__

#ifndef NDEBUG
    cout << "debug mode" << endl;
#endif  // NDEBUG

}

int main()
{
    case1();
}
