// Copyright (c) 2020 by Chrono
//
// g++ lambda.cpp -std=c++14 -o a.out;./a.out
// g++ lambda.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void my_square(int x)
{
    cout << x*x << endl;
}

void case1()
{
    auto pfunc = &my_square;

    (*pfunc)(3);
    pfunc(3);

    auto func = [](int x)
    {
        cout << x*x << endl;
    };

    func(3);
}

void case2()
{
    int n = 10;

    auto func = [=](int x)
    {
        cout << x*n << endl;
    };

    func(3);
}

void case3()
{
    auto f1 = [](){};

    auto f2 = []()
        {
            cout << "lambda f2" << endl;

            auto f3 = [](int x)
            {
                return x*x;
            };// lambda f3

            cout << f3(10) << endl;
        };  // lambda f2

    f1();
    f2();

    //f1 = f2;

    vector<int> v = {3, 1, 8, 5, 0};

    cout << *find_if(begin(v), end(v),
                [](int x)
                {
                    return x >= 5;
                }
            )
         << endl;
}

void case4()
{
    int x = 33;

    auto f1 = [=]()
    {
        //x += 10;
        cout << x << endl;
    };

    auto f2 = [&]()
    {
        x += 10;
    };

    auto f3 = [=, &x]()
    {
        x += 20;
    };

    f1();
    f2();
    cout << x << endl;
    f3();
    cout << x << endl;
}

class DemoLambda final
{
public:
    DemoLambda() = default;
   ~DemoLambda() = default;
private:
    int x = 0;
public:
    auto print()
    {
        //auto f = [=]()

        return [this]()
        {
            cout << "member = " << x << endl;
        };

    }
};

void case5()
{
    DemoLambda obj;

    auto f = obj.print();

    f();
}

void case6()
{
    auto f = [](const auto& x)
    {
        return x + x;
    };

    cout << f(3) << endl;
    cout << f(0.618) << endl;

    string str = "matrix";
    cout << f(str) << endl;
}

// demo for function + lambda
class Demo final
{
public:
    using func_type = std::function<void()>;
public:
    func_type print = [this]()
    {
        cout << "value = " << m_value << endl;
        cout << "hello function+lambda" << endl;
    };
private:
    int m_value = 10;
};

int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();

    Demo d;
    d.print();

    cout << "lambda demo" << endl;
}
