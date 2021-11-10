CC = g++

all: DynamicArray.o main.o
	$(CC) DynamicArray.o main.o -o main

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	$(CC) -g -c DynamicArray.cpp

main.o: DynamicArray.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main