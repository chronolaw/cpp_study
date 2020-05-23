add_executable(auto auto.cpp)
add_executable(const const.cpp)
add_executable(exception exception.cpp)
add_executable(lambda lambda.cpp)
add_executable(smart_ptr smart_ptr.cpp)

add_library(section2 auto.cpp const.cpp exception.cpp lambda.cpp smart_ptr.cpp)

install (TARGETS section2 DESTINATION bin)
install (FILES auto.cpp  const.cpp exception.cpp lambda.cpp smart_ptr.cpp DESTINATION include)
