cmake_minimum_required(VERSION 2.6)
project(cpp_study)
set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_BINARY_DIR}")
set(SOURCE_FILES  tutorial.cpp tutorial.h)

add_executable(cpp_study ${SOURCE_FILES} tutorial.cpp tutorial.h)
target_link_libraries(cpp_study ${EXTRA_LIBS})

include_directories("${PROJECT_SOURCE_DIR}/section0")
add_subdirectory(section0)
set(EXTRA_LIBS ${EXTRA_LIBS} section0)
