#pragma once
#include <stdio.h>
#include <iostream>

struct Fraction {
	int numerator;
	int denominator;
};

//The following two operators define the input and output operators for the Fraction struct.
std::istream& operator>> (std::istream& istr, Fraction& p);
std::ostream& operator<< (std::ostream& ostr, Fraction frac);

//The following two operators define the greater and less operators for the Fraction struct.
bool operator> (Fraction frac1, Fraction frac2);
bool operator< (Fraction frac1, Fraction frac2);

int findGCD(int a, int b);

Fraction simplifyFraction(Fraction& p);

//This function will input an array of an arbitrary data type.
template<class T>
void inputArray(T*& arr, int& size) {
	std::cin >> size;

	arr = (T*)calloc(size, sizeof(T));

	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

template<class T>
void outputArray(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

//This is a swap function, helps for the sort function.
template<class T>
void swapThem(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//This function will sort the array in an arbitrary order.
//Function pointer cmp return true if the first parameter satisfies the condition than the second parameter.
//FOR EXAMPLE: if we want to sort the array in increasing order, that means arr[i] < arr[i+1],
//Then cmp will return true if the first parameter is less than the second parameter.
// That means for i < j, we will only change the order of two elements arr[i], arr[j] if cmp(arr[i], arr[j]) returns false.
// Interchange sort used.
//This function should be called after the inputArray function.
template<class T>
void sortArray(T*& arr, int size, bool (*cmp)(T, T)) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (!(cmp(arr[i], arr[j]))) {
				swapThem(arr[i], arr[j]);
			}
		}
	}
}

//The following two functions define the greater and less comparison for a general data type T.
//WARNING: if the data T is user-defined, its > and < operators must be define before calling these functions.
template <class T>
bool isGreater(T x, T y) {
	return x > y;
}

template <class T>
bool isLess(T x, T y) {
	return x < y;
}

//This function will do the main process of the program.
//It will be called after the data type has been known, and a function pointer defines the order to sort has been defined.
template<class T>
void processFunction(T* arr, int size, bool (*cmp)(T, T)) {
	std::cout << "First, input the number of elements.\n";
	inputArray(arr, size);

	sortArray(arr, size, cmp);

	std::cout << "After sorting:\n";
	outputArray(arr, size);
}