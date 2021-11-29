CC = g++

all: Student.o main.o
	$(CC) Student.o main.o -o main

Student.o: Student.cpp Student.h
	$(CC) -g -c Student.cpp

main.o: Student.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main