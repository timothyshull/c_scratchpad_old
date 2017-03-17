cmake_minimum_required(VERSION 3.6)
project(nfa)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.c nfa.h nfa.c digraph.h digraph.c list.h list.c)
