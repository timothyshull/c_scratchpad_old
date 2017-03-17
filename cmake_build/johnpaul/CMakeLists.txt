project(johnpaul C CXX)

file(GLOB LIB_SOURCES *.cpp )
file(GLOB LIB_HEADERS *.h)
add_library( libjohnpaul.a ${LIB_SOURCES} ${LIB_HEADERS} )