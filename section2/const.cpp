// Copyright (c) 2020 by Chrono
//
// g++ const.cpp -std=c++11 -o a.out;./a.out
// g++ const.cpp -std=c++14 -o a.out;./a.out
// g++ const.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

void case1()
{
    using namespace std;

    //const int MAX_LEN       = 1024;
    const volatile int MAX_LEN       = 1024;
    const std::string NAME  = "metroid";

    auto ptr = (int*)(&MAX_LEN);
    *ptr = 2048;
    cout << MAX_LEN << endl;

}

void case2()
{
    using namespace std;

    int x = 100;

    const int& rx = x;
    const int* px = &x;

    cout << rx << *px << endl;

    string name = "uncharted";

    const string* ps1 = &name;
    //*ps1 = "spiderman";

    cout << *ps1 << endl;

    string* const ps2 = &name;
    *ps2 = "spiderman";

    cout << *ps2 << endl;

    const string* const ps3 = &name;
}

class DemoClass final
{
private:
    using mutex_type = int; // dummy type
private:
    mutable mutex_type  m_mutex;

    const long  MAX_SIZE = 256;
    int         m_value;
public:
    int get_value() const
    {
        return m_value;
    }

    void save_data() const
    {
        m_mutex++;
    }
};


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

    case1();
    case2();

    constexpr
    int fib5 = fib(5);

    cout << fib5 << endl;

    cout << "const demo" << endl;
}
