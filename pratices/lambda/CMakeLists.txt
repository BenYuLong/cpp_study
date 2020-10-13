project(lambda)

cmake_minimum_required(VERSION 3.16)

# find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../common)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

message("source dirs: ${PROJECT_SOURCE_DIR}")
message("binary dirs: ${PROJECT_BINARY_DIR}")

add_executable(lambdaExec lambda.cpp)

set (LINK_LIBRARY
    pthread
)

target_link_libraries(lambdaExec ${LINK_LIBRARY} -Wall)

add_library(lambda lambda.cpp)

install (TARGETS lambda DESTINATION bin)
install (FILES lambda.cpp DESTINATION include)
