// Copyright (c) 2020 by Chrono
//
// g++ test06.cpp -std=c++11 -o a.out;./a.out
// g++ test06.cpp -std=c++14 -o a.out;./a.out
// g++ test06.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <string>
#include <map>

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


int main()
{
    using namespace std;

    cout << "auto/decltype demo" << endl;
}
