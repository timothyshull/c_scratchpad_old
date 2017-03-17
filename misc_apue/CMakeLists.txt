cmake_minimum_required(VERSION 3.3)
project(adv_unix)

execute_process(COMMAND ./systype.sh OUTPUT_VARIABLE PLATFORM)

add_subdirectory(lib)
add_subdirectory(ch_1)
add_subdirectory(ch_3)
add_subdirectory(ch_4)
add_subdirectory(ch_5)