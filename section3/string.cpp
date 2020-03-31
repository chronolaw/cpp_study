// Copyright (c) 2020 by Chrono
//
// g++ string.cpp -std=c++11 -o a.out;./a.out
// g++ string.cpp -std=c++14 -o a.out;./a.out
// g++ string.cpp -std=c++14 -I../common -o a.out;./a.out

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

static
auto make_regex = [](const auto& txt)
{
    return std::regex(txt);
};

static
auto make_match = []()
{
    return std::smatch();
};

void case5()
{
    using namespace std;

    //using sregex = std::regex;
    //using cregex = std::regex;

    auto str = "neir:automata"s;

    auto reg  = make_regex(R"(^(\w+)\:(\w+)$)");
    auto what = make_match();

    assert(regex_match(str, what, reg));

    for(const auto& x : what) {
        cout << x << ',';
    }
    cout << endl;
}

void case6()
{
    using namespace std;

    auto str = "god of war"s;

    auto reg  = make_regex(R"((\w+)\s(\w+))");
    auto what = make_match();

    auto found = regex_search(
                    str, what, reg);

    assert(found);
    assert(!what.empty());
    assert(what[1] == "god");
    assert(what[2] == "of");

    auto new_str = regex_replace(
        str,
        make_regex(R"(\w+$)"),
        "peace"
    );

    cout << new_str << endl;
}



int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();

    using namespace std;

    cout << "string demo" << endl;
}
