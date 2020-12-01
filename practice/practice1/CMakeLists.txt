project(practice1)
cmake_minimum_required(VERSION 3.16)

add_executable(p_compile compile.cpp)
add_executable(preprocess preprocess.cpp)

add_library(practice1 compile.cpp)

install (TARGETS practice1 DESTINATION bin)
install (FILES compile.cpp DESTINATION include)
