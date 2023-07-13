cmake_minimum_required(VERSION 3.7.2)

project(echo-servers)

add_executable(echo-server-perthread echo-server-perthread.cpp)
target_link_libraries( echo-server-perthread pthread)


add_executable(echo-server-coroutine echo-server-coroutine.cpp)
target_include_directories(echo-server-coroutine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/asio/include)
target_link_libraries(echo-server-coroutine pthread)
target_compile_features(echo-server-coroutine PUBLIC cxx_std_20)
target_compile_options(echo-server-coroutine PUBLIC -fcoroutines)


add_executable(resumerable-coroutine resumerable-coroutine.cpp)
target_include_directories(resumerable-coroutine PUBLIC /usr/local/lib/asio)
target_link_libraries(resumerable-coroutine pthread)
target_compile_features(resumerable-coroutine PUBLIC cxx_std_20)
target_compile_options(resumerable-coroutine PUBLIC -fcoroutines)