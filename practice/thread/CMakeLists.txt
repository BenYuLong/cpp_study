project(thread)



add_executable(mutexCond mutexCond.cpp)
add_executable(producerConsumer producerConsumer.cpp)

set (LINK_LIBRARY
    pthread
)

target_link_libraries(mutexCond ${LINK_LIBRARY} -Wall)
target_link_libraries(producerConsumer ${LINK_LIBRARY} -Wall)


# add_library(section2 auto.cpp const.cpp exception.cpp lambda.cpp smart_ptr.cpp)

# install (TARGETS section2 DESTINATION bin)
# install (FILES auto.cpp  const.cpp exception.cpp lambda.cpp smart_ptr.cpp DESTINATION include)
