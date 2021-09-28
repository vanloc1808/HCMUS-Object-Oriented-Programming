#pragma once

#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>

template<class T>
class Array {
private:
	T* arr;
	int size;

public:
	//default constructor, arr = nullptr, size = 0.
	Array() {
		this->arr = nullptr;
		this->size = 0;
	}

	//constructor with given size, all elements are zero.
	Array(int givenSize) {
		//ensure that the size is nonnegative.
		if (givenSize < 0) {
			givenSize = 0;
		}

		this->size = givenSize;

		//allocate the dynamic array.
		this->arr = new T[this->size];

		if (this->arr) {
			for (int i = 0; i < this->size; i++) {
				this->arr[i] = 0;
			}
		}
	}

	Array(T givenArr[], int givenSize) {
		//ensure that the size is nonnegative.
		if (givenSize < 0) {
			givenSize = 0;
		}

		this->size = givenSize;
		
		//allocate the dynamic array.
		this->arr = new T[this->size];

		if (this->arr) {
			for (int i = 0; i < this->size; i++) {
				this->arr[i] = givenArr[i];
			}
		}
	}

	Array(const Array& givenArr) {
		//ensure that the size is nonnegative.
		if (givenArr.size >= 0) {
			this->size = givenArr.size;
		}

		//allocate the dynamic array.
		this->arr = new T[this->size];

		if (this->arr) {
			for (int i = 0; i < this->size; i++) {
				this->arr[i] = givenArr.arr[i];
			}
		}
	}

	~Array() {
		delete[]this->arr;
		this->arr = nullptr;
	}

	//WARNING: if an array want to use this method, the data type must have the << operator.
	void output() {
		for (int i = 0; i < this->size; i++) {
			std::cout << this->arr[i] << " ";
		}
		std::cout << "\n";
	}
};

#endif // !_ARRAY_H

