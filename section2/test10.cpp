// Copyright (c) 2020 by Chrono
//
// g++ test10.cpp -std=c++14 -o a.out;./a.out
// g++ test10.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <functional>

using namespace std;

void case1()
{
    auto f1 = [](){};

    auto f2 = []()
        {
            cout << "lambda f2" << endl;
        };

    f1();
    f2();

    //f1 = f2;
}

class DemoLambda final
{
public:
    DemoLambda() = default;
   ~DemoLambda() = default;
private:
    int x = 0;
public:
    void print()
    {
        //auto f = [=]()
        auto f = [this]()
        {
            cout << "member = " << x << endl;
        };

        f();
    }
};

void case2()
{
    DemoLambda obj;

    obj.print();
}

int main()
{
    case1();
    case2();

    cout << "lambda demo" << endl;
}
