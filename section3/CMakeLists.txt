add_executable(algo algo.cpp)
add_executable(container container.cpp)
add_executable(string string.cpp)
add_executable(thread thread.cpp)

add_library(section3 algo.cpp container.cpp string.cpp thread.cpp)

install (TARGETS section3 DESTINATION bin)
install (FILES algo.cpp  container.cpp string.cpp thread.cpp DESTINATION include)
