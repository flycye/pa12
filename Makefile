#Makefile for pa12

# executable
pa12: ArrayList.o pa12.o
		$(CXX) $(CXXFLAGS) ArrayList.o pa12.o -o pa12

# object files
ArrayList.o: ArrayList.cpp ArrayList.h
		$(CXX) $(CXXFLAGS) -c ArrayList.cpp

pa12.o: pa12.cpp ArrayList.h
		$(CXX) $(CXXFLAGS) -c pa12.cpp

clean:
		rm -f pa12 ArrayList.o pa12.o
