#!/usr/bin/python3

import pydemo

pydemo.info()

x = pydemo.add(1,2)
print(x)

s = pydemo.use_str("hello c++")
print(s)

t = pydemo.use_tuple((1,2, "matrix"))
print(t)

v = pydemo.use_list([1,2,3])
print(v)

p = pydemo.Point(999)
print(p.get())

p.set(1984)
assert(p.get() == 1984);
