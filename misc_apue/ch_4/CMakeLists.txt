cmake_minimum_required(VERSION 3.3)
project(ch_4)

include_directories(../include)
link_directories(../lib)

add_executable(4_3 4_3_main.c 4_3.c 4_3.h)
target_link_libraries(4_3 libapue.a)

add_executable(4_8 4_8.c)
target_link_libraries(4_8 libapue.a)

add_executable(4_9 4_9.c)
target_link_libraries(4_9 libapue.a)

add_executable(4_12 4_12.c)
target_link_libraries(4_12 libapue.a)

add_executable(4_16 4_16.c)
target_link_libraries(4_16 libapue.a)

add_executable(4_21 4_21.c)
target_link_libraries(4_21 libapue.a)

add_executable(4_22 4_22.c)
target_link_libraries(4_22 libapue.a)

add_executable(4_23 4_23.c)
target_link_libraries(4_23 libapue.a)

add_executable(4_24 4_24.c)
target_link_libraries(4_24 libapue.a)

add_executable(4_25 4_25.c)
target_link_libraries(4_25 libapue.a)