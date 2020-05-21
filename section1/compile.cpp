// Copyright (c) 2020 by Chrono
//
// g++ compile.cpp -Wall -Werror -std=c++11 -o a.out;./a.out
// g++ compile.cpp -Wall -Werror -std=c++14 -o a.out;./a.out
//
// g++ compile.cpp -DNDEBUG -std=c++11 -o a.out;./a.out
//
// gcc -E -dM - < /dev/null

#include <cassert>

#include <typeinfo>
#include <string>
#include <iostream>
#include <stdexcept>
#include <type_traits>

template<int N>
struct fib
{
    static_assert(N >= 0, "N must be postive");

    static const int value =
        fib<N - 1>::value + fib<N - 2>::value;
};

template<>
struct fib<0>
{
    static const int value = 1;
};

template<>
struct fib<1>
{
    static const int value = 1;
};

#if __cplusplus >= 201402
constexpr int const_fib(int n)
{
    if (n <= 1) {
        return 1;
    }

    return const_fib(n - 1) + const_fib(n - 2);
}
#else   // C++11
int const_fib(int n)
{
    return 42;
}
#endif

//[[deprecated("deadline:2020-12-31")]]      // c++14 or later
[[gnu::deprecated]] // c+11 or later
int old_func()
{
    //[[gnu::deprecated("I hate this")]]
    int value = 0;

    return value;
}

[[gnu::constructor]]
void first_func()
{
    // can not use cout!
    printf("before main()\n");
}

[[gnu::destructor]]
void last_func()
{
    // can not use cout!
    printf("after main()\n");
}

[[gnu::always_inline]] inline
int get_num()
{
    return 42;
}

[[noreturn]]
int case1(bool flag)
{
    throw std::runtime_error("XXX");
}

void case2()
{
    using namespace std;

    [[gnu::unused]]
    int nouse;

    cout << "case2" << endl;
}

[[gnu::hot]]
void case3()
{
    using namespace std;

    cout << "case3" << endl;
}

void case4()
{
    static_assert(sizeof(int) == 4, "int must be 32bit");
    static_assert(sizeof(long) >= 8, "must run on x64");
}

template<typename T>
void check_type(T v)
{
    using namespace std;

    static_assert(is_integral<T>::value, "int");
    //static_assert(is_pointer<T>::value, "ptr");
    //static_assert(is_default_constructible<T>::value, "is_default_constructible");

    cout << "static_assert : " << typeid(v).name() << endl;

    cout << is_void<void>::value << endl;
}

void case5()
{
    int     i = 10;
    int    *p = &i;

    assert(i > 0 && "i must be greater than zero");
    assert(p != nullptr);

    std::string str = "hello";
    assert(!str.empty());
}

int main()
{
    using namespace std;

    cout << fib<2>::value << endl;
    cout << fib<3>::value << endl;
    cout << fib<4>::value << endl;
    cout << fib<5>::value << endl;

    cout << const_fib(10) << endl;

    old_func();
    get_num();

    case2();
    case3();

    case4();
    case5();

    check_type(10);
    //check_type((void*)0);

    cout << "compile stage demo" << endl;
}
