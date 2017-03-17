cmake_minimum_required(VERSION 3.3)
project(ch_1)

include_directories(../include)
link_directories(../lib)

add_executable(1_3 1_3_main.c 1_3.c 1_3.h)
target_link_libraries(1_3 libapue.a)