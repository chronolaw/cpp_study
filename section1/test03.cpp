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
#else
#   error "c++ is too old"
#endif

#if __GNUC__ <= 4
    cout << "gcc is too old" << endl;
#else
    cout << "gcc is good enough" << endl;
#endif

#ifndef NDEBUG
    cout << "debug mode" << endl;
#endif

}

int main()
{
    case1();
}
