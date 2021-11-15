CC = g++

all: Point.o Circle.o main.o
	$(CC) Point.o Circle.o main.o -o main

Point.o: Point.cpp Point.h
	$(CC) -g -c Point.cpp

Circle.o: Circle.cpp Circle.h
	$(CC) -g -c Circle.cpp

main.o: Point.h Circle.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main