// Copyright (c) 2020 by Chrono
//
// pre-process source:
// g++ preprocess.cpp -E -o a.cxx
//
// g++ preprocess.cpp -std=c++98 -o a.out;./a.out
// g++ preprocess.cpp -std=c++11 -o a.out;./a.out
// g++ preprocess.cpp -std=c++14 -o a.out;./a.out
//
// g++ preprocess.cpp -DNDEBUG -std=c++11 -o a.out;./a.out
//
// show all predefined macro:
// g++ -E -dM - < /dev/null
// g++ -E -dM - < /dev/null > predef.cxx

// comment it for better pre-process output
#include <iostream>

using namespace std;

// you can try this
//#include "a.out"

void case1()
{
#
#if __linux__
#   define HAS_LINUX    1
#endif
#
    cout << "linux is " << HAS_LINUX << endl;
}

void case2()
{
#define CUBE(a) (a) * (a) * (a)

    cout << CUBE(10) << endl;
    cout << CUBE(15) << endl;

#undef CUBE

#ifdef AUTH_PWD
#  undef AUTH_PWD
#endif
#define AUTH_PWD  "xxx"

    cout << AUTH_PWD << endl;

#define MAX_BUF_LEN  65535
#define VERSION      "1.0.18"
}

// macro for convienient namespace
#define BEGIN_NAMESPACE(x)  namespace x {
#define END_NAMESPACE(x)    }

BEGIN_NAMESPACE(my_own)

class MyClass final
{
};

void case3()
{
    cout << "working in own namespace" << endl;
}

END_NAMESPACE(my_own)

#ifdef __cplusplus
    extern "C" {
#endif
    void a_c_function(int a);
#ifdef __cplusplus
    }
#endif

void case4()
{

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


#if defined(__cpp_decltype_auto)
    cout << "decltype(auto) enable" << endl;
#else
    cout << "decltype(auto) disable" << endl;
#endif //__cpp_decltype_auto

#ifndef NDEBUG
    cout << "debug mode" << endl;
#endif  // NDEBUG

}

int main()
{
    case1();
    case2();

    my_own::case3();

    [[gnu::unused]] // ignore warning
    my_own::MyClass obj;

    case4();

    cout << "pre-process demo" << endl;
}
