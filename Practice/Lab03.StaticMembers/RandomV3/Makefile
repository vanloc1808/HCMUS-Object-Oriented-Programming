CC = g++

all: main.o
	$(CC) main.o -o main

main.o:	Random.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main