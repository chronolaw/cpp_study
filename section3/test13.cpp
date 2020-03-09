// Copyright (c) 2020 by Chrono
//
// g++ test13.cpp -std=c++11 -o a.out;./a.out
// g++ test13.cpp -std=c++14 -o a.out;./a.out
// g++ test13.cpp -std=c++14 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>

#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void case1()
{
    vector<int> v = {1,3,1,7,5};

    auto n1 = std::count(
        begin(v), end(v), 1
    );

    int n2 = 0;
    for(auto x : v) {
        if (x == 1) {
            n2++;
        }
    }

    assert(n1 == n2);

    auto n = std::count_if(
        begin(v), end(v),
        [](auto x) {
            return x > 2;
        }
    );

    assert(n == 3);
}

void case2()
{
    vector<int> v = {1,2,3,4,5};

    auto iter1 = v.begin();
    auto iter2 = v.end();

    auto iter3 = std::begin(v);
    auto iter4 = std::end(v);

    assert(iter1 == iter3);
    assert(iter2 == iter4);
}

void case3()
{
    array<int, 5> arr = {0,1,2,3,4};

    auto b = begin(arr);
    auto e = end(arr);

    assert(distance(b, e) == 5);

    auto p = next(b);
    assert(distance(b, p) == 1);
    assert(distance(p, b) == -1);

    advance(p, 2);
    assert(*p == 3);
    assert(p == prev(e, 2));

}

void case4()
{
    vector<int> v = {3,5,1,7,10};

    for(const auto& x : v) {
        cout << x << ",";
    }
    cout << endl;

#if 0
    auto print = [](const auto& x)
    {
        cout << x << ",";
    };

    for_each(cbegin(v), cend(v), print);
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
    case2();
    case3();
    case4();

    using namespace std;

    cout << "algorithm demo" << endl;
}
