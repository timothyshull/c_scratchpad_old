cmake_minimum_required(VERSION 3.3)
project(ch_4)

include_directories(../include)
link_directories(../lib)

add_executable(5_4 5_4.c)
target_link_libraries(5_4 libapue.a)