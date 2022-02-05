cmake_minimum_required(VERSION 3.21)
project(Dismat_laba0_0 C)

set(CMAKE_C_STANDARD 23)

add_executable(Dismat_laba0_0 main.c)
add_executable(Test tests.c)

add_subdirectory(includes)

target_link_libraries(Dismat_laba0_0 includes)
target_link_libraries(Test includes)