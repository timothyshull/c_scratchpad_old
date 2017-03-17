CXX=clang++
CXXFLAGS=-Wall
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

all: $(OBJS)
	ar ru libjohnpaul.a $^
	ranlib libjohnpaul.a

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
	rm -f *.a