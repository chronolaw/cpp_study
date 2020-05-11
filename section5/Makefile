include ../common.mk

setup.done: ../section4/setup.sh
	sh ../section4/setup.sh

example_client_cpp14: setup.done
example_srv_cpp14: setup.done

example_client_cpp14_ld_flags=-lzmq -lpthread

example_srv_cpp14_cxx_flags=-I/usr/local/include/luajit-2.1 -ILuaBridge/Source -Icpr/include
example_srv_cpp14_ld_flags=cpr/lib/libcpr.a -lluajit-5.1 -lzmq -lcurl -lpthread -ldl 

examples: \
	example_client_cpp14 \
	example_srv_cpp14

clean: clean_extra
clean_extra:
	rm -fr setup.done cpr luajit2 LuaBridge json.hpp
