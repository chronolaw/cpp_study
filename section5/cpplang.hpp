// Copyright (c) 2020 by Chrono

#ifndef _CPP_LANG_HPP
#define _CPP_LANG_HPP

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

//never 'using namespace std;' in c++ header

// must be C++11 or later
#if __cplusplus < 201103
#   error "C++ is too old"
#endif  // __cplusplus >= 201402

static_assert(
    __GNUC__ >= 4, "GCC is too old");

#if __cplusplus >= 201402
#   define  CPP_DEPRECATED [[deprecated]]
#else
#   define  CPP_DEPRECATED [[gnu::deprecated]]
#endif  // __cplusplus >= 201402

// macro for convienient namespace
#define BEGIN_NAMESPACE(x)  namespace x {
#define END_NAMESPACE(x)    }

#endif  //_CPP_LANG_HPP

