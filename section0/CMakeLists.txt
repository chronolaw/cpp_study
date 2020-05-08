
add_executable(test test.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(section0 test.cpp)

install (TARGETS section0 DESTINATION bin)
install (FILES test.cpp DESTINATION include)
