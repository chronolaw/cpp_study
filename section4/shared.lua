#!/usr/local/bin/luajit

-- copyright (c) 2020 chrono

local ffi = require "ffi"

local ffi_load = ffi.load
local ffi_null = ffi.null
local ffi_cdef = ffi.cdef
local ffi_typeof = ffi.typeof
local ffi_new = ffi.new
local ffi_C = ffi.C

ffi_cdef[[
int num;
int my_add(int a, int b);
]]

print(jit.version)
print(jit.os)
print(jit.arch)
print(jit.status())

local shared = ffi_load("./liblua_shared.so")

print(shared.num)

local x = shared.my_add(1, 2)
print(x)
