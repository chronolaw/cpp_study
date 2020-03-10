// Copyright (c) 2020 by Chrono
//
// g++ test14.cpp -lpthread -std=c++11 -o a.out;./a.out
// g++ test14.cpp -lpthread -std=c++14 -o a.out;./a.out
// g++ test14.cpp -lpthread -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

#include <mutex>
#include <thread>

using namespace std;

void case3()
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

int main()
{
    case3();

    cout << "thread demo" << endl;
}
