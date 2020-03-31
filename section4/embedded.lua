#!/usr/local/bin/luajit

-- copyright (c) 2020 chrono

print('hello c++')

print(collectgarbage("count"))

print(os.time())
print(os.date("%Y-%m-%d"))

print(jit.version .. ' on ' ..jit.os)

