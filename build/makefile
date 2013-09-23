CXX=g++
CXXFLAGS=-g 
SRC=../src
VPATH=../src/frontend:../src/lib

reader: hash.o ir.so read.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

hash.o: hash.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

ir.so: ../src/ir/*.cpp
	$(CXX) $(CXXFLAGS) $^  -fPIC -shared -o $@