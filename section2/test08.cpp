// Copyright (c) 2020 by Chrono
//
// g++ test08.cpp -std=c++11 -o a.out;./a.out
// g++ test08.cpp -std=c++14 -o a.out;./a.out
// g++ test08.cpp -std=c++14 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <memory>
#include <string>

template<class T, class... Args>
std::unique_ptr<T>
my_make_unique(Args&&... args)
{
    return std::unique_ptr<T>(
            new T(std::forward<Args>(args)...));
}

void case1()
{
    using namespace std;

    unique_ptr<int> ptr1(new int(10));
    assert(*ptr1 = 10);
    assert(ptr1 != nullptr);

    unique_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");
    assert(ptr2->size() == 5);

    //ptr1++;
    //ptr2 += 2;

    //unique_ptr<int> ptr3;
    //*ptr3 = 42;

    auto ptr3 = make_unique<int>(42);
    assert(ptr3 && *ptr3 == 42);

    auto ptr4 = make_unique<string>("god of war");
    assert(!ptr4->empty());

    auto ptr5 = my_make_unique<long>(100L);
    assert(*ptr5 == 100);
}

void case2()
{
    using namespace std;

    auto ptr1 = make_unique<int>(42);
    assert(ptr1 && *ptr1 == 42);

    auto ptr2 = std::move(ptr1);
    assert(!ptr1 && ptr2);
}

void case3()
{
    using namespace std;

    auto ptr1 = make_shared<int>(42);
    assert(ptr1 && *ptr1 == 42);

    auto ptr2 = make_shared<string>("god of war");
    assert(!ptr2->empty());
}

int main()
{
    using namespace std;

    case1();
    case2();
    case3();

    cout << "smart_ptr demo" << endl;
}
