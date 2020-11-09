CC = g++
CXXFLAGS = -g -std=c++11

all:		run

run:		binary_search.o BinaryNode.o BinaryNodeTree.o BinarySearchTree.o
			$(CC) $(CXXFLAGS) -o run binary_search.o BinaryNode.o BinaryNodeTree.o BinarySearchTree.o

binary_search.o:		binary_search.cpp
			$(CC) $(CXXFLAGS) -c binary_search.cpp

BinaryNode.o:		BinaryNode.cpp BinaryNode.h
			$(CC) $(CXXFLAGS) -c BinaryNode.cpp

BinaryNodeTree.o:	BinaryNodeTree.cpp BinaryNodeTree.h
			$(CC) $(CXXFLAGS) -c BinaryNodeTree.cpp			

BinarySearchTree.o:		BinarySearchTree.cpp BinarySearchTree.h
			$(CC) $(CXXFLAGS) -c BinarySearchTree.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	$(CC) $(CXXFLAGS) -c PrecondViolatedExcep.cpp

NotFoundException.o: NotFoundException.cpp NotFoundException.h
	$(CC) $(CXXFLAGS) -c NotFoundException.cpp

clean:		
			rm *.o run