CC = g++

all: program.o
	$(CC) program.o -o c_program

progarm.o: program.cpp
	$(CC) -g -c program.cpp

clean:
	rm *.o
	rm c_program