CC = g++

all: C20120131_Store.o C20120131_Food.o C20120131_Cosmetics.o C20120131_HouseholdAppliances.o C20120131_ComplexStore.o C20120131_MBMarket.o main.o
	$(CC) C20120131_Store.o C20120131_Food.o C20120131_Cosmetics.o C20120131_HouseholdAppliances.o C20120131_ComplexStore.o C20120131_MBMarket.o main.o -o main

C20120131_Store.o: C20120131_Store.cpp C20120131_Store.h
	$(CC) -g -c C20120131_Store.cpp

C20120131_Food.o: C20120131_Food.cpp C20120131_Food.h
	$(CC) -g -c C20120131_Food.cpp

C20120131_Cosmetics.o: C20120131_Cosmetics.cpp C20120131_Cosmetics.h
	$(CC) -g -c C20120131_Cosmetics.cpp

C20120131_HouseholdAppliances.o: C20120131_HouseholdAppliances.cpp C20120131_HouseholdAppliances.h
	$(CC) -g -c C20120131_HouseholdAppliances.cpp

C20120131_ComplexStore.o: C20120131_ComplexStore.cpp C20120131_ComplexStore.h
	$(CC) -g -c C20120131_ComplexStore.cpp

C20120131_MBMarket.o: C20120131_MBMarket.cpp C20120131_MBMarket.h
	$(CC) -g -c C20120131_MBMarket.cpp

C20120131_main.o: C20120131_Store.h C20120131_Food.h C20120131_Cosmetics.h C20120131_HouseholdAppliances.h C20120131_ComplexStore.h C20120131_MBMarket.h C20120131_main.cpp
	$(CC) -g -c C20120131_main.cpp

clean: 
	rm *.o
	rm main