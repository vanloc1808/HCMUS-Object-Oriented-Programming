CC = g++

all: Fraction.o main.o
	$(CC) Fraction.o main.o -o main

Fraction.o: Fraction.cpp Fraction.h
	$(CC) -g -c Fraction.cpp

main.o: Fraction.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main