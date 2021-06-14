cmake_minimum_required(VERSION 3.19)
project(multithreading)

set(CMAKE_CXX_STANDARD 17)

add_executable(multithreading main.cpp Sockets.cpp Sockets.h UDPSockets.cpp UDPSockets.h Errors.h)
find_package(Threads REQUIRED)
target_link_libraries(multithreading Threads::Threads)
