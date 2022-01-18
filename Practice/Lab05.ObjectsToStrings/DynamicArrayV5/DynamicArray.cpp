#include <iostream>
#include <string>
#include <sstream>
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
    if (this->_a) {
        delete[] this->_a;
        this->_a = nullptr;
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
    if (this == &arr) {
        return *this;
    }
    
    if (this->_a) {
        delete[] this->_a;
        this->_a = nullptr;
    }

    this->_max = arr._max;
    this->_len = arr._len;

    this->_a = new int[this->_max];
    
    for (int i = 0; i < this->_len; i++) {
        this->_a[i] = arr._a[i];
    }

    return *this;
}

void DynamicArray::pushBack(int value) {
    this->_a[this->_len] = value;
    this->_len++;
}

int DynamicArray::getAt(int index) {
    return this->_a[index];
}

std::string DynamicArray::toString() {
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < this->_len; i++) {
        ss << this->_a[i];
        if (i != this->_len - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}