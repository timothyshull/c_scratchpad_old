find_package(BISON)
find_package(FLEX)

FLEX_TARGET(fb1-1_scanner fb1-1.l  ${CMAKE_CURRENT_BINARY_DIR}/fb1-1.c)
FLEX_TARGET(fb1-2_scanner fb1-2.l  ${CMAKE_CURRENT_BINARY_DIR}/fb1-2.c)

add_executable(fb1-1 ${FLEX_fb1-1_scanner_OUTPUTS})
target_link_libraries(fb1-1 /usr/local/Cellar/flex/2.6.0/lib/libfl.a)

add_executable(fb1-2 ${FLEX_fb1-2_scanner_OUTPUTS})
target_link_libraries(fb1-2 /usr/local/Cellar/flex/2.6.0/lib/libfl.a)

BISON_TARGET(fb1-5_parser fb1-5.y ${CMAKE_CURRENT_BINARY_DIR}/fb1-5_y.cpp COMPILE_FLAGS "-d")
FLEX_TARGET(fb1-5_lexer fb1-5.l  ${CMAKE_CURRENT_BINARY_DIR}/fb1-5_l.cpp)
ADD_FLEX_BISON_DEPENDENCY(fb1-5_lexer fb1-5_parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(fb1-5
        ${BISON_fb1-5_parser_OUTPUTS}
        ${FLEX_fb1-5_lexer_OUTPUTS}
        )

target_link_libraries(fb1-5 /usr/local/Cellar/flex/2.6.0/lib/libfl.a)
target_link_libraries(fb1-5 /usr/local/Cellar/bison/3.0.4/lib/liby.a)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L/usr/local/Cellar/flex/2.6.0/lib -lfl")