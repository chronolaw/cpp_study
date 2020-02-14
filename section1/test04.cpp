// Copyright (c) 2020 by Chrono
//
// g++ test04.cpp -Wall -Werror -std=c++11 -o a.out;./a.out
// g++ test04.cpp -Wall -Werror -std=c++14 -o a.out;./a.out
//
// g++ test04.cpp -DNDEBUG -std=c++11 -o a.out;./a.out
//
// gcc -E -dM - < /dev/null

#include <iostream>
#include <stdexcept>

//[[deprecated("deadline:2020-12-31")]]      // c+14 or later
[[gnu::deprecated]] // c+11 or later
int old_func()
{
    [[gnu::deprecated("I hate this")]]
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

[[gnu::always_inline]] inline
int get_num()
{
    return 42;
}

[[noreturn]]
int case1(bool flag)
{
    throw std::runtime_error("XXX");
}

void case2()
{
    using namespace std;

    [[gnu::unused]]
    int nouse;

    cout << "case2" << endl;
}

[[gnu::hot]]
void case3()
{
    using namespace std;

    cout << "case3" << endl;
}

int main()
{
    old_func();
    get_num();

    case2();
    case3();
}
