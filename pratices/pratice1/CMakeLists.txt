project(pratice1)
cmake_minimum_required(VERSION 3.16)

add_executable(p_compile compile.cpp)

add_library(pratice1 compile.cpp)

install (TARGETS pratice1 DESTINATION bin)
install (FILES compile.cpp DESTINATION include)
