CC = g++

all: Point.o Rectangle.o main.o
	$(CC) Point.o Rectangle.o main.o -o main

Point.o: Point.cpp Point.h
	$(CC) -g -c Point.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CC) -g -c Rectangle.cpp

main.o: Point.h Rectangle.h main.cpp	
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main