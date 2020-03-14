// Copyright (c) 2020 by Chrono
//
// sudo apt-get install libmsgpack-dev
//
// /usr/include/msgpack
// g++ msgpack.cpp -std=c++11 -o a.out;./a.out
// g++ msgpack.cpp -std=c++14 -o a.out;./a.out

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <msgpack.hpp>

using namespace std;

void case1()
{
    vector<int> v = {1,2,3,4,5};

    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, v);

    cout << sbuf.size() << endl;

    auto handle = msgpack::unpack(sbuf.data(), sbuf.size());
    auto obj = handle.get();
    cout << obj << endl;

    decltype(v) v2;
    obj.convert(v2);

    assert(std::equal(begin(v), end(v), begin(v2)));
}

class Book final
{
public:
    int         id;
    string      title;
    set<string> tags;
public:
    MSGPACK_DEFINE(id, title, tags);
};

void case2()
{
    Book book1 = {1, "1984", {"a","b"}};

    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, book1);

    auto obj = msgpack::unpack(sbuf.data(), sbuf.size()).get();

    Book book2;
    obj.convert(book2);

    assert(book2.id == book1.id);
    assert(book2.tags.size() == 2);
    cout << book2.title << endl;
}

int main()
{
    case1();
    case2();

    cout << "msgpack demo" << endl;
}
