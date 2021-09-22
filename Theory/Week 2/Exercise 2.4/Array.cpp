#include <iostream>
#include "Array.h"

//Function used to initialize an empty array.
void Array::init() {
	this->arr = NULL;
	this->size = 0;
}

//Function used to input a new array.
//First, a temporary variable is used to store the size.
//Then, we will check if it is possible to allocate the pointer arr.
//Return false if arr = NULL,
//Return true if we can allocate.
//Later function will assume that the pointer is successfully allocated, and will not check again.
bool Array::input() {
	int tempSize = 0;
	
	std::cout << "Enter the number of elements. ";
	std::cin >> tempSize;

	this->arr = new int[tempSize];

	if (!this->arr) {
		return false;
	}

	this->size = tempSize;

	std::cout << "Enter each elements.\n";
	for (int i = 0; i < tempSize; i++) {
		std::cin >> this->arr[i];
	}

	return true;
}

//Function used to output an array, just consequentially print them.
void Array::output() {
	for (int i = 0; i < this->size; i++) {
		std::cout << this->arr[i] << " ";
	}
}

//Function used to get the value of an array's size.
int Array::getSize() {
	return this->size;
}

//Function used to get the value of the element at position index.
//This function will not check if index is valid, 
//which needs to be checked in the function calling it.
int Array::getElement(int index) {
	return this->arr[index];
}

//Function used to assign a new value, the variable newValue, to the element at position index.
//This function will not check if index is valid, 
//which needs to be checked in the function calling it.
void Array::assignElement(int index, int newValue) {
	this->arr[index] = newValue;
}

//Function used to find an element in the array.
//Because the array is arbitrary (not sorted),
//The algorithm used is sequential search (linear search).
//Return the index of position which is found,
//Return -1 if cannot find.
int Array::findElement(int toFind) {
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] == toFind) {
			return i;
		}
	}

	//Cannot find
	return -1;
}

//Function used to swap two integers, with a temporary variable.
void swapThem(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//Function used to sort the array.
//Function pointer cmp return true if the first parameter satisfies the condition more than the second parameter.
//FOR EXAMPLE: if we want to sort the array in increasing order, that means arr[i] < arr[i+1],
//Then cmp will return true if the first parameter is less than the second parameter.
// That means for i < j, we will only change the order of two elements arr[i], arr[j] if cmp(arr[i], arr[j]) returns FALSE.
// Algorithm used: interchange sort.
void Array::sortArray(bool (*cmp)(int, int)) {
	for (int i = 0; i < this->size; i++) {
		for (int j = i + 1; j < this->size; j++) {
			if (cmp(this->arr[i], this->arr[j]) == false) {
				swapThem(this->arr[i], this->arr[j]);
			}
		}
	}
}

void Array::freeArray() {
	delete[] this->arr;
	this->arr = nullptr;
}