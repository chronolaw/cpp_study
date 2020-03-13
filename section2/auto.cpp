// Copyright (c) 2020 by Chrono
//
// g++ auto.cpp -std=c++11 -o a.out;./a.out
// g++ auto.cpp -std=c++14 -o a.out;./a.out
// g++ auto.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include <signal.h>

void case1()
{

    int     i = 0;
    double  x = 1.0;

    std::string str = "hello";
    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};

    std::map<int, std::string>::const_iterator iter = m.begin();

    //using namespace std;
    //cout << i << x;
}

void case2()
{
    auto  i = 0;
    //auto  i{0} ;
    auto  x = 1.0;

    auto  str = "hello";
    //decltype("hello")  str = "hello";

    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};

    auto  iter = m.begin();

    auto  f = bind1st(std::less<int>(), 2);

    //using namespace std;
    //cout << typeid(str).name() << endl;
}

void case3()
{
    auto x = 0L;
    auto y = &x;
    auto z {&x};
}

class X final
{
    //auto a = 10;
    int a = 10;
};

void case4()
{
    auto    x = 10L;

    auto&       x1 = x;
    auto*       x2 = &x;
    const auto& x3 = x;
    auto        x4 = &x3;

    using namespace std;

    cout << *x2 << endl;
    cout << *x4 << endl;
    //cout << typeid(x4).name() << endl;
}

void case5()
{
    int x = 0;

    decltype(x)     x1;
    decltype(x)&    x2 = x;
    decltype(x)*    x3;
    decltype(&x)    x4;
    decltype(&x)*   x5;
    decltype(x2)    x6 = x2;

    using int_ptr = decltype(&x);
    using int_ref = decltype(x)&;
}

void case6()
{
    int x = 0;

    decltype(auto)     x1 = (x);
    decltype(auto)     x2 = &x;
    decltype(auto)     x3 = x1;
}

auto get_a_set()
{
    std::set<int> s = {1,2,3};

    return s;
}

void case7()
{
    using namespace std;

    vector<int> v = {2,3,5,7,11};

    for(const auto& i : v) {
        cout << i << ",";
    }
    cout << endl;

    for(auto& i : v) {
        i++;
        cout << i << ",";
    }
    cout << endl;
}

class DemoClass final
{
public:
    using sig_func_ptr_t = decltype(&signal) ;
public:
    using set_type      = std::set<int>;

private:
    set_type    m_set;

    using iter_type = decltype(m_set.begin());
    iter_type   m_pos;
};

int main()
{
    using namespace std;

    case1();
    case2();
    case3();
    case4();
    case5();
    case6();
    case7();

    cout << "auto/decltype demo" << endl;
}
