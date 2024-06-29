.SUFFIXES = .cpp .o
CXX = g++

EXE = test1
INC = ..
AUX = $(INC)/dfa.o
OBJ = dfa-test1.o

all : $(EXE)

test1 : dfa-test1.o
	g++ -o test1 dfa-test1.o $(AUX)

dfa-test1.o : dfa-test1.cpp
	g++ -c dfa-test1.o dfa-test1.cpp

clean :
	rm $(OBJS)