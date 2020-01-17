// Copyright (c) 2020 by Chrono
//
// g++ test02.cpp -std=c++11 -o a.out;./a.out
// g++ test02.cpp -std=c++14 -o a.out;./a.out
//

#include <iostream>


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
int main()
{
    case1();
    case2();
}
