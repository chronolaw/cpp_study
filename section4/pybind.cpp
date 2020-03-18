// Copyright (c) 2020 by Chrono
//
// apt install python3-pip
// pip3 install pybind11
//
// apt install python3-dev
// mkdir build && cd build
// cmake .. -DPYBIND11_TEST=OFF
//
// g++ -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` pybind.cpp -o pydemo`python3-config --extension-suffix`

#include <pybind11/pybind11.h>

int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(pydemo, m)
{
    m.doc() = "pybind11 doc";
    m.def("add", &add, "add func");
}

#if 0

#include <iostream>

int main()
{
    using namespace std;

    cout << "pybind demo" << endl;
}
#endif
