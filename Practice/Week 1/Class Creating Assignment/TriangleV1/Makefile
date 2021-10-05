CC = g++

all: Point.o Triangle.o main.o
	$(CC) Point.o Triangle.o main.o -o main

Point.o: Point.cpp Point.h
	$(CC) -g -c Point.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CC) -g -c Triangle.cpp

main.o: Point.h Triangle.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *o
	rm main