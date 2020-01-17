// Copyright (c) 2020 by Chrono
//
// g++ test02.cpp -std=c++11 -o a.out;./a.out
// g++ test02.cpp -std=c++14 -o a.out;./a.out
//

#include <iostream>

#define BEGIN_NAMESPACE(x)  namespace x {
#define END_NAMESPACE(x)    }

void case1()
{
    using std::cout;
    using std::endl;

    cout << "using std::xxx" << endl;
}

void case2()
{
    using namespace std;

    cout << "using namespace std" << endl;
}

BEGIN_NAMESPACE(my_own)

class MyClass final
{
};

void case3()
{
    using namespace std;

    cout << "working in own namespace" << endl;
}

END_NAMESPACE(my_own)

int main()
{
    case1();
    case2();

    my_own::case3();
    my_own::MyClass obj;
}
