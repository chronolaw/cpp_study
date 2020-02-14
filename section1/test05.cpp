// Copyright (c) 2050 by Chrono
//
// g++ test05.cpp -std=c++11 -o a.out;./a.out
// g++ test05.cpp -std=c++14 -o a.out;./a.out
//

#include <iostream>
#include <string>
#include <set>


class DemoClass final
{
public:
    using string_type   = std::string;
    using uint32_type   = uint32_t;
    using set_type      = std::set<int>;
public:
  void set_name(const string_type& str);
private:
  string_type   m_name;
  uint32_type   m_age;
  set_type      m_books;
};


int main()
{
    using namespace std;

    cout << "show your class." << endl;
}
