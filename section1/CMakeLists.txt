add_executable(codestyle codestyle.cpp)
add_executable(compile compile.cpp)
add_executable(oop oop.cpp)
add_executable(preprocess preprocess.cpp)

add_library(section1 codestyle.cpp compile.cpp oop.cpp preprocess.cpp)

install (TARGETS section1 DESTINATION bin)
install (FILES codestyle.cpp  compile.cpp oop.cpp preprocess.cpp DESTINATION include)
