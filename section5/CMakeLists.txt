add_executable(client client.cpp)

add_executable(srv srv.cpp)

add_library(section5 client.cpp conf.lua Config.hpp cpplang.hpp hello.hpp SalesData.hpp SpinLock.hpp srv.cpp Summary.hpp Zmq.hpp)
install (TARGETS section5 DESTINATION bin)

install (FILES client.cpp conf.lua Config.hpp cpplang.hpp hello.hpp SalesData.hpp SpinLock.hpp srv.cpp Summary.hpp Zmq.hpp DESTINATION include)
