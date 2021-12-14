CC = g++

all: DynamicArray.o Point.o Line.o Rectangle.o Circle.o Triangle.o Fraction.o FractionOperators.o DynamicArray.o main.o
	$(CC) DynamicArray.o Point.o Line.o Rectangle.o Circle.o Triangle.o Fraction.o FractionOperators.o DynamicArray.o main.o -o main

Point.o: Point.cpp Point.h
	$(CC) -g -c Point.cpp

Line.o: Line.cpp Line.h
	$(CC) -g -c Line.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CC) -g -c Rectangle.cpp

Circle.o: Circle.cpp Circle.h
	$(CC) -g -c Circle.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CC) -g -c Triangle.cpp

Fraction.o: Fraction.cpp Fraction.h
	$(CC) -g -c Fraction.cpp

FractionOperators.o: FractionOperators.cpp Fraction.h
	$(CC) -g -c FractionOperators.cpp

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	$(CC) -g -c DynamicArray.cpp

main.o: Point.h Line.h Rectangle.h Circle.h Triangle.h Fraction.h DynamicArray.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main