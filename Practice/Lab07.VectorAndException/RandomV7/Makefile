CC = g++

all: Random.o main.o
	$(CC) Random.o main.o -o main

Random.o: Random.cpp Random.h
	$(CC) -g -c Random.cpp

main.o:	Random.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main