// Copyright (c) 2020 by Chrono
//
// g++ client.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -o c.out;./c.out
// g++ client.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -g -O0 -o c.out
// g++ client.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -g -O0 -o c.out;./c.out

//#include <iostream>

#include "cpplang.hpp"
#include "SalesData.hpp"
#include "SpinLock.hpp"
#include "Zmq.hpp"

// you should put json.hpp in ../common
#include "json.hpp"

static
auto debug_print = [](auto& b)
{
    using json_t = nlohmann::json;

    json_t j;

    j["id"] = b.id();
    j["sold"] = b.sold();
    j["revenue"] = b.revenue();
    //j["average"] = b.average();

    std::cout << j.dump(2) << std::endl;
};

int main()
try
{
    USING_NAMESPACE(std);
    USING_NAMESPACE(cpp_study);

    cout << "hello cpp_study" << endl;

    // sales data

    SalesData book1("isbn001");

    book1.inc_sold(10);
    book1.inc_revenue(100);

    debug_print(book1);

    auto buf = book1.pack();
    cout << buf.size() << endl;

    // zmq send

    using zmq_ctx = ZmqContext<1>;

    auto sock = zmq_ctx::send_sock();

    sock.connect("tcp://127.0.0.1:5555");
    assert(sock.connected());

    auto len = sock.send(buf.data(), buf.size());
    assert(len == buf.size());

    cout << "send len = " << len << endl;
}
catch(std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
