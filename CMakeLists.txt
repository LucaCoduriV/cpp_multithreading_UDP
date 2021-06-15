cmake_minimum_required(VERSION 3.19)
project(multithreading)

set(CMAKE_CXX_STANDARD 17)

add_executable(multithreading main.cpp Sockets.cpp Sockets.h UDPSockets.cpp
        UDPSockets.h Errors.h Datagram.h Utils.cpp Utils.h AckHandler.cpp
        AckHandler.h Tester.h Utils_Test.h AckHandler_Test.h)

find_package(Threads REQUIRED)
target_link_libraries(multithreading Threads::Threads)
if(WIN32)
    target_link_libraries(multithreading wsock32 ws2_32)
endif()
