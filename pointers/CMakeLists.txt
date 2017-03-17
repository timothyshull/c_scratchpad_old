cmake_minimum_required(VERSION 3.6)
project(pointer_practice)

set(CMAKE_CXX_STANDARD 11)

add_executable(reference_to_pointer reference_to_pointer.cpp)
add_executable(return_reference return_reference.cpp)
add_executable(pointer_addition pointer_addition.cpp)
add_executable(free_on_null free_on_null.c)
add_executable(double_free double_free.c)
add_executable(basic_arrays basic_arrays.c)