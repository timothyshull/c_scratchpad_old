CXX=clang++
CXXFLAGS=-Wall
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -dynamiclib -fPIC $^ -o libgeorgeringo.dylib -install_name '$(CURDIR)/libgeorgeringo.dylib'

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
	rm -f *.dylib