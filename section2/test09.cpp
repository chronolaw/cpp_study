// Copyright (c) 2020 by Chrono
//
// g++ test09.cpp -std=c++11 -o a.out;./a.out
// g++ test09.cpp -std=c++14 -o a.out;./a.out
// g++ test09.cpp -std=c++14 -I../common -o a.out;./a.out

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
};

[[noreturn]]
void raise(const char* msg)
{
    throw runtime_error(msg);
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

int main()
{
    case1();

    cout << "exception demo" << endl;
}
