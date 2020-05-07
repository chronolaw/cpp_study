CXX_FLAGS=-Wall

all: examples

example_%_cpp14: %.cpp
	g++ -std=c++14 -o $@ $^ $(CXX_FLAGS) $($@_cxx_flags) $($@_ld_flags) 

example_%_cpp11: %.cpp
	g++ -std=c++11 -o $@ $^ $(CXX_FLAGS) $($@_cxx_flags) $($@_ld_flags)

example_%_cpp98: %.cpp
	g++ -std=c++98 -o $@ $^ $(CXX_FLAGS) $($@_cxx_flags) $($@_ld_flags)

clean:
	rm -fr example_*
