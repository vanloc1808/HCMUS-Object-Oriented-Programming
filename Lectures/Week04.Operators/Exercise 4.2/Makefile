CC = g++

all: Monomial.o main.o
	$(CC) Monomial.o main.o -o main

Monomial.o: Monomial.cpp Monomial.h
	$(CC) -g -c Monomial.cpp

main.o: Monomial.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main