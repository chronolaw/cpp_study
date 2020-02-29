// Copyright (c) 2020 by Chrono
//
// g++ test10.cpp -std=c++14 -o a.out;./a.out
// g++ test10.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

void case1()
{
    using namespace std;

    auto f1 = [](){};

    auto f2 = []()
        {
            cout << "lambda f2" << endl;
        };

    f1();
    f2();

    //f1 = f2;
}

int main()
{
    case1();

    using namespace std;

    cout << "lambda demo" << endl;
}
