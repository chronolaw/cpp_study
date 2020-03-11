// Copyright (c) 2020 by Chrono
//
// g++ test14.cpp -lpthread -std=c++11 -o a.out;./a.out
// g++ test14.cpp -lpthread -std=c++14 -o a.out;./a.out
// g++ test14.cpp -lpthread -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

#include <atomic>
#include <mutex>
#include <future>
#include <thread>

using namespace std;

void case1()
{
    static once_flag flag;

    auto f = []()
    {
        cout << "tid=" <<
            this_thread::get_id() << endl;

        std::call_once(flag,
            [](){
                cout << "only once" << endl;
            }
        );
    };

    thread t1(f);
    thread t2(f);

    t1.join();
    t2.join();
}

void case2()
{
    //static int n = 0;
    thread_local int n = 0;

    auto f = [&](int x)
    {
        n += x;

        cout << n;
        cout << ", tid=" <<
            this_thread::get_id() << endl;
    };

    thread t1(f, 10);
    thread t2(f, 20);

    t1.join();
    t2.join();
}


void case3()
{
    static atomic_flag flag {false};
    static atomic_int  n;

    auto f = [&]()
    {
        auto value = flag.test_and_set();

        if (value) {
            cout << "flag has been set." << endl;
        } else {
            cout << "set flag by " <<
                this_thread::get_id() << endl;
        }

        n += 100;
        cout << n << endl;

    };

    thread t1(f);
    thread t2(f);

    t1.join();
    t2.join();
}

#if 0

int fib(int n)
{
    if (n < 2) {
        return 1;
    }

    return fib(n-1) + fib(n-2);
};

void case4()
{
    auto f1 = std::async(fib, 20);

    cout << "future async ..." << endl;

    f1.wait();
    cout << f1.get() << endl;
}

#endif

void case4()
{
    auto task = [](auto x)
    {
        using namespace std::chrono_literals;

        this_thread::sleep_for( x * 1ms);

        cout << "sleep for " << x << endl;
    };

    auto f = std::async(task, 10);

    f.wait();
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    cout << "thread demo" << endl;
}
