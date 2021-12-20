CC = g++

all: Employee.o ProductEmployee.o DailyEmployee.o Manager.o main.o
	$(CC) Employee.o ProductEmployee.o DailyEmployee.o Manager.o main.o -o main

Employee.o: Employee.cpp Employee.h
	$(CC) -g -c Employee.cpp

ProductEmployee.o: ProductEmployee.cpp ProductEmployee.h
	$(CC) -g -c ProductEmployee.cpp

DailyEmployee.o: DailyEmployee.cpp DailyEmployee.h
	$(CC) -g -c DailyEmployee.cpp

Manager.o: Manager.cpp Manager.h
	$(CC) -g -c Manager.cpp

main.o: Employee.h ProductEmployee.h DailyEmployee.h Manager.h main.cpp
	$(CC) -g -c main.cpp

clean:
	rm *.o
	rm main