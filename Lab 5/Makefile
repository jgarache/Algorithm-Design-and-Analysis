# variable definitions
CC     = g++
CFLAGS =
LIBS   =

# target to build "all"
all: BST.exe

# target for building Inserting 
BST.exe: BST.o main.o
	${CC} -o $@ $^ ${LIBS}

# dependencies for the objects
BST.o: BST.cpp BST.h
main.o: main.cpp BST.h

# target to clean up extra files
clean:
	${RM} main *.o 

# generic target to compile a .cpp file to a .o file with the same name
.c.o:
	${CC} ${CFLAGS} -c $<
