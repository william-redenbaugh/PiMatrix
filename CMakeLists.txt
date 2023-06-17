cmake_minimum_required(VERSION 3.17)
PROJECT(PiMatrix)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

file(GLOB_RECURSE INCL_HDRS include/*.h)

ADD_EXECUTABLE(PiMatrix  
    ${INCL_HDRS} ${SRCS_HAL} ${HDRS_HAL}
    ${SRCS} ${HDRS})

target_include_directories(PiMatrix
    PRIVATE
    include/)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(PiMatrix PRIVATE Threads::Threads)