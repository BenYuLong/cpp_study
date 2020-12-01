project(pratice0)

cmake_minimum_required(VERSION 3.16)

# find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../common)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

message("source dirs: ${PROJECT_SOURCE_DIR}")
message("binary dirs: ${PROJECT_BINARY_DIR}")

add_executable(pratice0Exec test.cpp)

set (LINK_LIBRARY
    pthread
)

target_link_libraries(pratice0Exec ${LINK_LIBRARY} -Wall)

add_library(pratice0 test.cpp)

install (TARGETS pratice0 DESTINATION bin)
install (FILES test.cpp DESTINATION include)
