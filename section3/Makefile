include ../common.mk

example_thread_cpp14_ld_flags=-lpthread
example_thread_cpp11_ld_flags=-lpthread


ifeq ($(HAS_CPP14), yes)
examples: \
	example_algo_cpp14 \
	example_container_cpp14 \
	example_string_cpp14 \
	example_thread_cpp14
endif
