#!/usr/local/bin/luajit

local ffi = require "ffi"

local ffi_load = ffi.load
local ffi_null = ffi.null
local ffi_cdef = ffi.cdef
local ffi_typeof = ffi.typeof
local ffi_new = ffi.new
local ffi_C = ffi.C

ffi_cdef[[
int my_add(int a, int b);
]]

local shared = ffi_load("./lua_shared.so")

local x = shared.my_add(1, 2)
print(x)
