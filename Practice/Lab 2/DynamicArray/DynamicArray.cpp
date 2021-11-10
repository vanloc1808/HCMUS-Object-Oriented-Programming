#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    this->_max = this->INITIAL_SIZE;
    this->_len = 0;
    this->_a = new int[this->INITIAL_SIZE];
}

DynamicArray::DynamicArray(int sz) {
    for (int i = 0; i < sz; i++) {
        this->_a[i] = 0;
    }
}

DynamicArray::DynamicArray(const DynamicArray& arr) {
    this->_max = arr._max;
    this->_len = arr._len;
    this->_a = new int[this->_max];

    for (int i = 0; i < this->_len; i++) {
        this->_a[i] = arr._a[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] this->_a;
    this->_a = NULL;
}

void DynamicArray::pushBack(int value) {
    this->_a[this->_len] = value;
    this->_len++;
}

int DynamicArray::getAt(int index) {
    return this->_a[index];
}

void DynamicArray::output() {
    for (int i = 0;  i < this->_len; i++) {
        std::cout << this->_a[i] << " ";
    }
    std::cout << "\n";
}