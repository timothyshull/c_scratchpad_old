cmake_minimum_required(VERSION 3.3)
project(ch_3)

include_directories(../include)
link_directories(../lib)

add_executable(3_1 3_1_main.c 3_1.c 3_1.h 3_2_main.c 3_4_main.c)
target_link_libraries(3_1 libapue.a)

add_executable(3_2 3_2_main.c 3_2.c 3_2.h)
target_link_libraries(3_2 libapue.a)

add_executable(3_4 3_4_main.c 3_4.c 3_4.h)
target_link_libraries(3_4 libapue.a)

add_executable(3_10 3_10_main.c 3_10.c 3_10.h)
target_link_libraries(3_10 libapue.a)

add_executable(3_11 3_11_main.c 3_11.c 3_11.h)
target_link_libraries(3_11 libapue.a)