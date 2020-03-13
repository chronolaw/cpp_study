// Copyright (c) 2020 by Chrono
//
// g++ exception.cpp -std=c++11 -o a.out;./a.out
// g++ exception.cpp -std=c++14 -o a.out;./a.out
// g++ exception.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <stdexcept>

using namespace std;

class my_exception : public std::runtime_error
{
public:
    using this_type     = my_exception;
    using super_type    = std::runtime_error;
public:
    my_exception(const char* msg):
        super_type(msg)
    {}

    my_exception() = default;
   ~my_exception() = default;
private:
    int code = 0;
};

[[noreturn]]
void raise(const char* msg)
{
    throw my_exception(msg);
    //throw runtime_error(msg);
}

void case1()
try
{
    raise("error occured");
}
catch(const exception& e)
{
    cout << e.what() << endl;
}

void case2() noexcept
{
    cout << "noexcept" << endl;
}

void case3() noexcept
{
    throw "Oh My God";
}

int main()
{
    case1();
    case2();
    //case3();

    cout << "exception demo" << endl;
}
