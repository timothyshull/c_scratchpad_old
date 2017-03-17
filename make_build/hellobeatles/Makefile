CXX=clang++
CXXFLAGS=-Wall
ROOT=..
INC=-I../

hellobeatles: hellobeatles.o
	$(CXX) $(CXXFLAGS) hellobeatles.o -o hellobeatles -L../johnpaul -L../georgeringo -ljohnpaul -lgeorgeringo

hellobeatles.o:
	$(CXX) $(CXXFLAGS) hellobeatles.cpp -c -o hellobeatles.o $(INC)

clean:
	rm -f *.o
	rm -f hellobeatles