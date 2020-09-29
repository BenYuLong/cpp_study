project(Section1)
cmake_minimum_required(VERSION 3.16)

add_executable(compile compile.cpp)

add_library(section1 compile.cpp)

install (TARGETS section1 DESTINATION bin)
install (FILES compile.cpp DESTINATION include)
