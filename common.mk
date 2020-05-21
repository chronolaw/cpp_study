CXX_FLAGS=-Wall
CXX=g++

HAS_CPP14=$(shell \
	echo > /tmp/dummy.cpp ; \
	if $(CXX) -std=c++14 -c -o /dev/null /tmp/dummy.cpp 2>/dev/null ; then \
		echo yes ; \
	else \
		echo no ; \
	fi)

HAS_CPP11=$(shell \
	echo > /tmp/dummy.cpp ; \
	if $(CXX) -std=c++11 -c -o /dev/null /tmp/dummy.cpp 2>/dev/null ; then \
		echo yes ; \
	else \
		echo no ; \
	fi)

ifeq ($(HAS_CPP14), yes)
	PREFER_STANDARD:=cpp14
else
ifeq ($(HAS_CPP11), yes)
	PREFER_STANDARD:=cpp11
endif
endif

all: examples

example_%_cpp14: %.cpp
	$(CXX) -std=c++14 -o $@ $^ $(CXX_FLAGS) $($@_cxx_flags) $($@_ld_flags)

example_%_cpp11: %.cpp
	$(CXX) -std=c++11 -o $@ $^ $(CXX_FLAGS) $($@_cxx_flags) $($@_ld_flags)

example_%_cpp98: %.cpp
	$(CXX) -std=c++98 -o $@ $^ $(CXX_FLAGS) $($@_cxx_flags) $($@_ld_flags)

clean:
	rm -fr example_*
