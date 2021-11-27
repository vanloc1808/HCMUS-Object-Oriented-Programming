#include <iostream>
#include <string>
#include <sstream>
#include <climits>
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
    if (this->_len == this->_max) {
        int* a = new int[this->_len];

        for (int i = 0; i < this->_len; i++) {
            a[i] = this->_a[i];
        }

        delete[] this->_a;
        this->_a = new int[this->_len + this->INITIAL_SIZE];

        for (int i = 0; i < this->_len; i++) {
            this->_a[i] = a[i];
        }
    }
    this->_a[this->_len] = value;
    this->_len++;
}

int DynamicArray::getAt(int index) {
    try {
        if (index < 0 || index >= this->_len) {
            throw "Index out of bound";
        } else {
            return this->_a[index];
        }
    } catch (const char* message) {
        std::cout << message << "\n";
    }
    return INT_MIN;
}

std::string DynamicArray::toString() const {
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

std::istream& operator>>(std::istream& inDev, DynamicArray& arr) {
    inDev >> arr._len;
    if (arr._max < arr._len) {
        arr._max = arr._len;
    }

    if (arr._a) {
        delete[] arr._a;
    }

    arr._a = new int[arr._max];

    for (int i = 0; i < arr._len; i++) {
        inDev >> arr._a[i];
    }

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const DynamicArray& arr) {
    outDev << arr.toString();

    return outDev;
}