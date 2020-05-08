include ../common.mk

example_cpr_cpp14_cxx_flags=-Icpr/include
example_cpr_cpp14_ld_flags=cpr/lib/libcpr.a -lpthread -lcurl

example_curl_cpp14_ld_flags=-lcurl

example_gperf_cpp14_cxx_flags=-g -O0
example_gperf_cpp14_ld_flags=-lprofiler -ltcmalloc

example_luajit_cpp14_cxx_flags=-I/usr/local/include/luajit-2.1 -ILuaBridge/Source
example_luajit_cpp14_ld_flags=-Wl,-rpath,/usr/local/lib -lluajit-5.1 -ldl

example_protobuf_cpp14_ld_flags=-lprotobuf

example_pybind_cpp14_cxx_flags=$(shell python3 -m pybind11 --includes)
example_pybind_cpp14_ld_flags=$(shell python3 -m pybind11 --includes)

example_zmq_cpp14_ld_flags=-lzmq -lpthread

sample.pb.cc: sample.proto
	protoc --cpp_out=. sample.proto

example_cpr_cpp14: setup.done
example_curl_cpp14: setup.done
example_gperf_cpp14: setup.done
example_json_cpp14: setup.done
example_msgpack_cpp14: setup.done
example_protobuf_cpp14: setup.done sample.pb.cc
example_zmq_cpp14: setup.done
example_luajit_cpp14: setup.done

setup.done: setup.sh
	sh setup.sh

example_pybind11_library.done: pybind.cpp
	$(CXX) $^ -std=$(subst cpp,c++,$(PREFER_STANDARD)) -shared -fPIC $$(python3 -m pybind11 --includes) \
		-o pydemo$$(python3-config --extension-suffix)
	touch $@

examples: \
	example_cpr_cpp14 \
	example_curl_cpp14 \
	example_gperf_cpp14 \
	example_json_cpp14 \
	example_msgpack_cpp14 \
	example_protobuf_cpp14 \
	example_zmq_cpp14 \
	example_luajit_cpp14 \
	example_pybind11_library.done

clean: clean_extra
clean_extra:
	rm -fr setup.done example_pybind11_library.done cpr luajit2 LuaBridge json.hpp pydemo*.so
