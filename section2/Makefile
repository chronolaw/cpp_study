include ../common.mk

ifeq ($(HAS_CPP14), yes)
examples: \
	example_auto_cpp14 \
	example_const_cpp14 \
	example_exception_cpp14 \
	example_lambda_cpp14 \
	example_smart_ptr_cpp14
endif

ifeq ($(HAS_CPP11), yes)
examples: \
	example_exception_cpp11
endif
