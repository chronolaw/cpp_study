// Copyright (c) 2020 by Chrono
//
// g++ test11.cpp -std=c++11 -o a.out;./a.out
// g++ test11.cpp -std=c++14 -o a.out;./a.out
// g++ test11.cpp -std=c++14 -I../common -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <string>
#include <regex>

void case1()
{
    using namespace std;

    string str = "abc";

    assert(str.length() == 3);
    assert(str < "xyz");
    assert(str.substr(0, 1) == "a");
    assert(str[1] == 'b');
    assert(str.find("1") == string::npos);
    assert(str + "d" == "abcd");
}

void case2()
{
    // enable literal suffix 's'
    using namespace std::literals::string_literals;

    using std::string;

    auto str = "std string"s;

    assert(str.length() > 0);

    assert("time"s.size() == 4);
}

void case3()
{
    using namespace std;

    auto str = R"(nier:automata)";

    auto str1 = R"(char""'')";
    auto str2 = R"(\r\n\t\")";
    auto str3 = R"(\\\$)";
    auto str4 = "\\\\\\$";

    auto str5 = R"==(R"(xxx)")==";

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
}

void case4()
{
    using namespace std;

    assert(stoi("42") == 42);
    assert(stol("253") == 253L);
    assert(stod("2.0") == 2.0);

    assert(to_string(1984) == "1984");
}

class my_string_view final
{
public:
    using this_type = my_string_view;
    using string_type = std::string;
    using string_ref_type = const std::string&;

    using char_ptr_type = const char*;
    using size_type = size_t;
private:
    char_ptr_type ptr = nullptr;
    size_type len = 0;
public:
    my_string_view() = default;
   ~my_string_view() = default;

    my_string_view(string_ref_type str) noexcept
        : ptr(str.data()), len(str.length())
    {}
public:
    char_ptr_type data() const
    {
        return ptr;
    }

    size_type size() const
    {
        return len;
    }
};

int main()
{
    case1();
    case2();
    case3();
    case4();

    using namespace std;

    cout << "string demo" << endl;
}
