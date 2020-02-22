// Copyright (c) 2020 by Chrono
//
// g++ test07.cpp -std=c++11 -o a.out;./a.out
// g++ test07.cpp -std=c++14 -o a.out;./a.out
// g++ test07.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>


constexpr
int fib(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    using namespace std;

    constexpr
    int fib5 = fib(5);

    cout << fib5 << endl;

    cout << "const demo" << endl;
}
