// Copyright (c) 2020 by Chrono
//
// g++ test13.cpp -std=c++11 -o a.out;./a.out
// g++ test13.cpp -std=c++14 -o a.out;./a.out
// g++ test13.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

void case1()
{
    vector<int> v = {3,5,1,7,10};

    for(const auto& x : v) {
        cout << x << ",";
    }
    cout << endl;

#if 0
    auto f = [](const auto& x)
    {
        cout << x << ",";
    };

    for_each(cbegin(v), cend(v), f);
#endif

#if 1
    for_each(
        cbegin(v), cend(v),
        [](const auto& x)
        {
            cout << x << ",";
        }
    );
#endif

    cout << endl;
}

int main()
{
    case1();

    using namespace std;

    cout << "algorithm demo" << endl;
}
