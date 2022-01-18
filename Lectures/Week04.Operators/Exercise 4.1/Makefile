CC = g++

all: Fraction.o FractionOperators.o main.o
	$(CC) Fraction.o FractionOperators.o main.o -o main

Fraction.o: Fraction.cpp Fraction.h
	$(CC) -g -c Fraction.cpp

FractionOperators.o: FractionOperators.cpp Fraction.h
	$(CC) -g -c FractionOperators.cpp

main.o: Fraction.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *o 
	rm main