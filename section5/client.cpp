// Copyright (c) 2020 by Chrono
//
// g++ client.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -o c.out;./c.out
// g++ client.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -g -O0 -o c.out
// g++ client.cpp -std=c++14 -I../common -I../common/include -lzmq -lpthread -g -O0 -o c.out;./c.out

//#include <iostream>

#include "cpplang.hpp"
#include "SalesData.hpp"
#include "Zmq.hpp"

// you should put json.hpp in ../common
#include "json.hpp"

USING_NAMESPACE(std);
USING_NAMESPACE(cpp_study);

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

// sales data
static
auto make_sales = [=](const auto& id, auto s, auto r)
//-> msgpack::sbuffer
{
    return SalesData(id, s, r).pack();

#if 0
    SalesData book(id);

    book.inc_sold(s);
    book.inc_revenue(r);

    debug_print(book);

    auto buf = book.pack();
    cout << buf.size() << endl;

    //SalesData book2 {buf};
    //assert(book.id() == book2.id());
    //debug_print(book2);

    return buf;
#endif
};

// zmq send
static
auto send_sales = [](const auto& addr, const auto& buf)
{
    using zmq_ctx = ZmqContext<1>;

    auto sock = zmq_ctx::send_sock();

    sock.connect(addr);
    assert(sock.connected());

    auto len = sock.send(buf.data(), buf.size());
    assert(len == buf.size());

    cout << "send len = " << len << endl;
};

int main()
try
{
    cout << "hello cpp_study client" << endl;

    //auto buf = make_sales("001", 10, 100);
    //send_sales("tcp://127.0.0.1:5555", buf);

    send_sales("tcp://127.0.0.1:5555",
             make_sales("001", 10, 100));

    std::this_thread::sleep_for(100ms);

    send_sales("tcp://127.0.0.1:5555",
             make_sales("002", 20, 200));

}
catch(std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
