CXX=clang++
CXXFLAGS=-Wall
SRCS = $(wildcard *.cpp)
OBJS = $(wildcard *.o)

all: john.o paul.o johnpaul.o
	ar ru libjohnpaul.a $^
	ranlib libjohnpaul.a

john.o:
	$(CXX) $(CXXFLAGS) john.cpp -c -o john.o

paul.o:
	$(CXX) $(CXXFLAGS) paul.cpp -c -o paul.o

johnpaul.o:
	$(CXX) $(CXXFLAGS) johnpaul.cpp -c -o johnpaul.o

clean:
	rm -f *.o
	rm -f *.a