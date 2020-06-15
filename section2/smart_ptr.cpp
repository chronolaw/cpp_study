// Copyright (c) 2020 by Chrono
//
// g++ smart_ptr.cpp -std=c++11 -o a.out;./a.out
// g++ smart_ptr.cpp -std=c++14 -o a.out;./a.out
// g++ smart_ptr.cpp -std=c++14 -I../common -o a.out;./a.out

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
    assert(*ptr1 == 10);
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

    shared_ptr<int> ptr1(new int(10));
    assert(*ptr1 = 10);

    shared_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");

    auto ptr3 = make_shared<int>(42);
    assert(ptr3 && *ptr3 == 42);

    auto ptr4 = make_shared<string>("zelda");
    assert(!ptr4->empty());
}

void case4()
{
    using namespace std;

    auto ptr1 = make_shared<int>(42);
    assert(ptr1 && ptr1.unique() );

    auto ptr2 = ptr1;
    assert(ptr1 && ptr2);

    assert(ptr1 == ptr2);
    assert(!ptr1.unique() && ptr1.use_count() == 2);
    assert(!ptr2.unique() && ptr2.use_count() == 2);
}

class DemoShared final
{
public:
    DemoShared() = default;
   ~DemoShared()
   {
       // do some blocking thing ...
   }
};

class Node final
{
public:
    using this_type     = Node;
    //using shared_type   = std::shared_ptr<this_type>;
    using shared_type   = std::weak_ptr<this_type>;
public:
    shared_type     next;
public:
    Node() = default;
   ~Node()
    {
       using namespace std;
       cout << "node dtor" << endl;
    }
};

void case5()
{
    using namespace std;

    auto n1 = make_shared<Node>();
    auto n2 = make_shared<Node>();

    assert(n1.use_count() == 1);
    assert(n2.use_count() == 1);

    n1->next = n2;
    n2->next = n1;

    assert(n1.use_count() == 1);
    assert(n2.use_count() == 1);

    if (!n1->next.expired()) {
        auto ptr = n1->next.lock();
        assert(ptr == n2);
    }

    //assert(n1.use_count() == 2);
    //assert(n2.use_count() == 2);
}

int main()
{
    using namespace std;

    case1();
    case2();
    case3();
    case4();
    case5();

    cout << "smart_ptr demo" << endl;
}
