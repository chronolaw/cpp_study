// Copyright (c) 2020 by Chrono
//
// apt install python3-pip
// pip3 install pybind11
//
// apt install python3-dev
// mkdir build && cd build
// cmake .. -DPYBIND11_TEST=OFF
//
// g++ pybind.cpp -std=c++11 -shared -fPIC `python3 -m pybind11 --includes` -o pydemo`python3-config --extension-suffix`
// g++ pybind.cpp -std=c++14 -shared -fPIC `python3 -m pybind11 --includes` -o pydemo`python3-config --extension-suffix`

#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace std;

namespace py = pybind11;

class Point final
{
private:
    int x = 0;
public:
    Point() = default;
   ~Point() = default;

    Point(int a) : x(a) {}
public:
    int get() const
    {
        return x;
    }

    void set(int a)
    {
        x = a;
    }
};

PYBIND11_MODULE(pydemo, m)
{
    m.doc() = "pybind11 demo doc";

    m.def("info",
        []()
        {
            //cout << "c++ version = " << __cplusplus << endl;
            //cout << "gcc version = " << __VERSION__ << endl;
            //cout << "libstdc++   = " << __GLIBCXX__ << endl;
            py::print("c++ version =", __cplusplus);
            py::print("gcc version =", __VERSION__);
            py::print("libstdc++   =", __GLIBCXX__);
        }
    );

    m.def("add",
        [](int a, int b)
        {
            return a + b;
        }
    );

    m.def("use_str",
        [](const string& str)
        {
            //cout << str << endl;
            py::print(str);
            return str + "!!";
        }
    );

    m.def("use_tuple",
        [](tuple<int, int, string> x)
        {
            get<0>(x)++;
            get<1>(x)++;
            get<2>(x)+= "??";

            return x;
        }
    );

    m.def("use_list",
        [](const vector<int>& v)
        {
            auto vv = v;

            //for(auto& x : vv) {
            //    //cout << x << ",";
            //}
            //cout << endl;
            py::print("input :", vv);

            vv.push_back(100);

            return vv;
        }
    );

    py::class_<Point>(m, "Point")
        .def(py::init())
        .def(py::init<int>())
        .def("get", &Point::get)
        .def("set", &Point::set)
        ;
}

#if 0
void info()
{
    cout << "c++ version = " << __cplusplus << endl;
    cout << "gcc version = " << __VERSION__ << endl;
    cout << "libstdc++   = " << __GLIBCXX__ << endl;
}

int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(pydemo, m)
{
    m.doc() = "pybind11 demodoc";

    m.def("info", &info, "cpp info");
    m.def("add", &add, "add func");
}
#endif

#if 0

int main()
{
    cout << "pybind demo" << endl;
}
#endif
