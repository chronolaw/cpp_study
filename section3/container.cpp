// Copyright (c) 2020 by Chrono
//
// g++ container.cpp -std=c++11 -o a.out;./a.out
// g++ container.cpp -std=c++14 -o a.out;./a.out
// g++ container.cpp -std=c++14 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <complex>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Point final
{
//private:
public:
    int x = 0;
public:
    Point(int a) noexcept : x(a)
    {
        cout << "ctor" << x << endl;
    }

    Point() noexcept
    {
        cout << "ctor" << x << endl;
    }

   ~Point() noexcept
    {
        cout << "dtor" << x << endl;
    }

    Point(const Point& p) noexcept
    {
        x = p.x;
        cout << "copy ctor"<< x  << endl;
    }

    Point(Point&& p) noexcept
    {
        x = std::move(p.x);
        cout << "move ctor" << x << endl;
    }
};

void case1()
{
    vector<Point> v;
    v.reserve(10);

    Point p;

    v.push_back(p);
    v.push_back(std::move(p));

    v.emplace_back(1);
}

void case2()
{
    array<int, 2> arr;
    assert(arr.size() == 2);

    vector<int> v(2);
    for(int i = 0; i < 10; i++) {
        v.emplace_back(i);
    }
    //cout << v.size() << endl;
    assert(v.size() == 12);

    deque<int> d;
    d.emplace_back(9);
    d.emplace_front(1);
    assert(d.size() == 2);
}

bool operator<(const Point& a, const Point& b)
{
    return a.x < b.x;
}

void case3()
{
    set<Point> s;

    s.emplace(7);
    s.emplace(3);

    for(auto& p : s) {
        cout << p.x << ",";
    }
    cout << endl;
}

#if 0
using complex_t = complex<double>;

// add < compare to complex
namespace std{
bool operator<(const complex_t& a, const complex_t& b)
{
    return a.real() < b.real();
}
}

void case3()
{
    set<complex_t> s;

    s.emplace(3, 1);
    s.emplace(1, 1);

    for(auto& c : s) {
        cout << c << ",";
    }
    cout << endl;
}
#endif

void case4()
{
    set<int> s = {7, 3, 9};

    for(auto& x : s) {
        cout << x << ",";
    }
    cout << endl;

    auto comp = [](auto a, auto b)
    {
        return a > b;
    };

    set<int, decltype(comp)> gs(comp);

    std::copy(begin(s), end(s),
              inserter(gs, gs.end()));

    for(auto& x : gs) {
        cout << x << ",";
    }
    cout << endl;
}

void case5()
{
    using map_type =
        unordered_map<int, string>;

    map_type dict;

    dict[1] = "one";
    dict.emplace(2, "two");
    dict[10] = "ten";

    for(auto& x : dict) {
        cout << x.first << "=>"
             << x.second << ",";
    }
    cout << endl;
}

bool operator==(const Point& a, const Point& b)
{
    return a.x == b.x;
}

void case6()
{
    auto hasher = [](const auto& p)
    {
        return std::hash<int>()(p.x);
    };

    unordered_set<Point, decltype(hasher)> s(10, hasher);

    s.emplace(7);
    s.emplace(3);

    for(auto& p : s) {
        cout << p.x << ",";
    }
    cout << endl;
}


int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();

    cout << "containter demo" << endl;
}
