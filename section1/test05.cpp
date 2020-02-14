// Copyright (c) 2050 by Chrono
//
// g++ test05.cpp -std=c++11 -o a.out;./a.out
// g++ test05.cpp -std=c++14 -o a.out;./a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

#if 1

class Interface {};

class Implement final : public Interface
{
public:
    using super_type = Interface;
    using this_type  = Implement;
private:
};

#endif

#if 1

struct KafkaConfig final
{
    int             id;
    std::string     ip_addr;
};

class DemoClass final
{
public:
    using this_type         = DemoClass;
    using kafka_conf_type   = KafkaConfig;

public:
    using string_type   = std::string;
    using uint32_type   = uint32_t;

    using set_type      = std::set<int>;
    using vector_type   = std::vector<std::string>;

public:
    DemoClass() = default;
   ~DemoClass() = default;

public:
    void set_name(const string_type& str);

private:
    string_type     m_name  = "tom";
    uint32_type     m_age   = 23;
    set_type        m_books;

private:
    kafka_conf_type m_conf;
};

#endif



int main()
{
    using namespace std;

    cout << "show your class." << endl;
}
