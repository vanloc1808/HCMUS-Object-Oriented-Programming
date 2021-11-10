CC = g++

all: Point.o Line.o main.o 
	$(CC) Point.o Line.o main.o  -o main

Point.o: Point.cpp Point.h
	$(CC) -g -c Point.cpp

Line.o: Line.cpp Line.h
	$(CC) -g -c Line.cpp

main.o: Point.h Line.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main