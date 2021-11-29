CC = g++

all: DateV5.o main.o 
	$(CC) DateV5.o main.o -o main

DateV5.o: DateV5.cpp DateV5.h
	$(CC) -g -c DateV5.cpp

main.o:	DateV5.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main