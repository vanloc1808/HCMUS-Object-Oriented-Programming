CC = g++

all: TimeV5.o main.o 
	$(CC) TimeV5.o main.o -o main

TimeV5.o: TimeV5.cpp TimeV5.h
	$(CC) -g -c TimeV5.cpp

main.o:	TimeV5.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main