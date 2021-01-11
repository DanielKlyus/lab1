cmake_minimum_required(VERSION 3.17)
project(lab_TritSet)

set(CMAKE_CXX_STANDARD 14)

add_executable(labTrit header.h test.cpp TritSet.cpp main.cpp)

add_subdirectory(googletest-master)
#add_subdirectory(googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(labTrit gtest gtest_main)
