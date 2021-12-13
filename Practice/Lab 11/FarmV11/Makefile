CC = g++

all: Animal.o Farm.o main.o
	$(CC) Animal.o Farm.o main.o -o main

Animal.o: Animal.cpp Animal.h
	$(CC) -g -c Animal.cpp

Farm.o: Farm.cpp Farm.h
	$(CC) -g -c Farm.cpp

clean:
	rm *.o
	rm main