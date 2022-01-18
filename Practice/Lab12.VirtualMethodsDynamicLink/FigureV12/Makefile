CC = g++

all: Figure.o main.o
	$(CC) Figure.o main.o -o main

Figure.o: Figure.cpp Figure.h
	$(CC) -g -c Figure.cpp

main.o: Figure.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main