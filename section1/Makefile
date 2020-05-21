include ../common.mk


ifeq ($(HAS_CPP14), yes)
examples: \
	example_codestyle_cpp14 \
	example_compile_cpp14 \
	example_oop_cpp14 \
	example_preprocess_cpp14
endif

ifeq ($(HAS_CPP11), yes)
examples: \
	example_codestyle_cpp11 \
	example_compile_cpp11 \
	example_oop_cpp11 \
	example_preprocess_cpp11
endif

# example_preprocess_cpp98 is showing version check with compile failed.
# please explicit using `make example_preprocess_cpp98` under section1 folder
