// Copyright (c) 2020 by Chrono
//
// g++ test04.cpp -Wall -Werror -std=c++11 -o a.out;./a.out
// g++ test04.cpp -Wall -Werror -std=c++14 -o a.out;./a.out
//
// g++ test04.cpp -DNDEBUG -std=c++11 -o a.out;./a.out
//
// gcc -E -dM - < /dev/null

#include <iostream>

//[[deprecated]]      // c+14 or later
//[[gnu::deprecated]] // c+11 or later
int old_func()
{
    //[[gnu::deprecated]]
    int value = 0;

    return value;
}

[[gnu::constructor]]
void first_func()
{
    // can not use cout!
    printf("before main()\n");
}

[[gnu::destructor]]
void last_func()
{
    // can not use cout!
    printf("after main()\n");
}

void case1()
{
    using namespace std;

    [[gnu::unused]]
    int nouse;

    cout << "case1" << endl;
}

void case2()
{
    using namespace std;

    cout << "case2" << endl;
}

int main()
{
    //old_func();

    case1();
    case2();
}
