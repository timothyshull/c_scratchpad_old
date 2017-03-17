CXX=clang++
CXXFLAGS=-Wall
SRCS = $(wildcard *.cpp)
OBJS = $(wildcard *.o)

all: george.o ringo.o georgeringo.o
	$(CXX) -dynamiclib -fPIC $^ -o libgeorgeringo.dylib -install_name '$(CURDIR)/libgeorgeringo.dylib'

john.o:
	$(CXX) $(CXXFLAGS) george.cpp -c -o george.o

paul.o:
	$(CXX) $(CXXFLAGS) ringo.cpp -c -o ringo.o

johnpaul.o:
	$(CXX) $(CXXFLAGS) georgeringo.cpp -c -o georgeringo.o

clean:
	rm -f *.o
	rm -f *.dylib