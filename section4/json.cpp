// Copyright (c) 2020 by Chrono
//
// git clone git@github.com:nlohmann/json.git
// wget https://github.com/nlohmann/json/releases/download/v3.7.3/json.hpp
//
// g++ json.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>

// you should put json.hpp in ../common
#include "json.hpp"

using namespace std;

using json_t = nlohmann::json;

void case1()
{
    json_t j;
    j["age"] = 23;
    j["name"] = "spiderman";
    j["gear"]["suits"] = "2099";
    j["jobs"] = {"superhero", "neighborhood"};

    vector<int> v = {1,2,3};
    j["numbers"] = v;

    map<string, int> m = {{"one",1}, {"two", 2}};
    j["kv"] = m;

    cout << j.dump() << endl;
    cout << j.dump(2) << endl;

#if 0
    json_t j = {
        {"age", 23},
        {"name", "spiderman"},
        {"jobs", {"superhero", "neighborhood"}},
        {"gear", {"suits", "2099"}}
    };

    cout << j.dump(2) << endl;
#endif
}

void case2()
{
    string str = R"({
        "name": "peter",
        "age" : 23,
        "married" : true
    })";

    auto j = json_t::parse(str);

    assert(j["age"] == 23);
    assert(j["name"] == "peter");

    cout << j.dump(2) << endl;
}

void case3()
{
    auto txt = "bad:data"s;

    try
    {
        auto j = json_t::parse(txt);
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    //cout << json_t::meta() << endl;
    cout << json_t::meta().dump(2) << endl;

    case1();
    case2();
    case3();

    cout << "json demo" << endl;
}
