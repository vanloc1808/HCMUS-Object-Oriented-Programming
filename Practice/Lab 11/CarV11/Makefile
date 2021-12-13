CC = g++

all: main.o
	$(CC) main.o -o main

main.o: Car.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main