#ifndef _DYNAMICARRAY_H
#define _DYNAMICARRAY_H

#include <iostream>
#include <sstream>

template<class T>
class DynamicArray {
private:
    const int INITIAL_SIZE = 128;

private:
    T* _a;
    int _len;
    int _max;

public:
    DynamicArray() {
        this->_max = this->INITIAL_SIZE;
        this->_len = 0;
        this->_a = new T[this->INITIAL_SIZE];
    }

    DynamicArray(int sz) {
        this->_a = new int[sz];
        for (int i = 0; i < sz; i++) {
            this->_a[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& arr) {
        this->_max = arr._max;
        this->_len = arr._len;
        this->_a = new T[this->_max];

        for (int i = 0; i < this->_len; i++) {
            this->_a[i] = arr._a[i];
        }
    }

    ~DynamicArray() {
        if (this->_a) {
        delete[] this->_a;
        this->_a = nullptr;
    }
    }

    DynamicArray& operator=(const DynamicArray& arr) {
        if (this == &arr) {
        return *this;
        }
        
        if (this->_a) {
            delete[] this->_a;
            this->_a = nullptr;
        }

        this->_max = arr._max;
        this->_len = arr._len;

        this->_a = new T[this->_max];
        
        for (int i = 0; i < this->_len; i++) {
            this->_a[i] = arr._a[i];
        }

        return *this;
    }

    void pushBack(T value) {
        if (this->_len == this->_max) {
        T* a = new T[this->_len];

        for (int i = 0; i < this->_len; i++) {
            a[i] = this->_a[i];
        }

        delete[] this->_a;
        this->_a = new T[this->_len + this->INITIAL_SIZE];

        for (int i = 0; i < this->_len; i++) {
            this->_a[i] = a[i];
        }
        }
        this->_a[this->_len] = value;
        this->_len++;
    }
    
    int getAt(int index) {
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

    std::string toString() const {
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

    friend std::istream& operator>>(std::istream& inDev, DynamicArray& arr) {
        inDev >> arr._len;
        if (arr._max < arr._len) {
            arr._max = arr._len;
        }

        if (arr._a) {
            delete[] arr._a;
        }

        arr._a = new T[arr._max];

        for (int i = 0; i < arr._len; i++) {
            inDev >> arr._a[i];
        }

        return inDev;
    }

    friend std::ostream& operator<<(std::ostream& outDev, const DynamicArray& arr) {
        outDev << arr.toString();

        return outDev;
    }

    T maxElement() {
        T maxValue = this->_a[0];

        for (int i = 1; i < this->_len; i++) {
            if (this->_a[i] > maxValue) {
                maxValue = this->_a[i];
            }
        }
        
        return maxValue;
    }

    void sort() {
        for (int i = 0; i < this->_len; i++) {
            for (int j = i + 1; j < this->_len; j++) {
                if (this->_a[i] > this->_a[j]) {
                    T temp = this->_a[i];
                    this->_a[i] = this->_a[j];
                    this->_a[j] = temp;
                }
            }
        }
    }
};

#endif