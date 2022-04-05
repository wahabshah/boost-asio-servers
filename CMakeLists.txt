cmake_minimum_required(VERSION 3.7.2)

project(echo-servers)

add_executable(echo-server-perthread echo-server-perthread.cpp)

target_link_libraries( echo-server-perthread pthread)

add_executable(echo-server-perthread2 echo-server-perthread2.cpp)

target_link_libraries(echo-server-perthread2 pthread)