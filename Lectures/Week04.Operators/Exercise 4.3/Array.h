#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>
#include <limits.h>

template<class T>
class Array {
private:
    T* m_arr;
    int m_size;

public:
    //default constructor
    //initialize arr = nullptr and size = 0
    Array() {
        this->m_arr = nullptr;
        this->m_size = 0;
    }

    //fully-parameterized constructor
    Array(T* arr, int size) {
        delete[] this->m_arr;

        //ensure that the size is nonnegative.
        if (size < 0) {
            size = 0;
        }

        this->m_size = size;
        
        this->m_arr = new T[size];

        for (int i = 0; i < size; i++) {
            this->m_arr[i] = arr[i];
        }
    }

    //copy constructor
    //assume that arr is a valid array, which means that the size is nonnegative.
    Array(const Array& arr) {
        delete[] this->m_arr;

        this->m_size = arr.m_size;

        this->m_arr = new T[this->m_size];

        for (int i = 0; i < this->m_size; i++) {
            this->m_arr[i] = arr.m_arr[i];
        }
    }

    //assigning operator
    //return *this to be the same as built-in types.
    Array<T>& operator=(Array& arr) {
        delete[] this->m_arr;

        this->m_size = arr.m_size;

        this->m_arr = new T[this->m_size];

        for (int i = 0; i < this->m_size; i++) {
            this->m_arr[i] = arr.m_arr[i];
        }

        return *this;
    }

    //operator subscript (array index operator)
    //return INT_MIN if pos is not a valid index,
    //which can lead to unexpected error.
    T operator[](int pos) {
        T res = INT_MIN;

        if (pos < 0 || pos >= this->m_size) {
            return res;
        }

        return this->m_arr[pos];
    }

    operator T*() const {
           T* res = nullptr;

           if (this->m_size == 0) {
               return res;
           }

           return this->m_arr;
    }

    //The following two operators used to input and output an array.
    //Because they are not operators of this class,
    //the keyword "friend" is used to access private members.
    friend std::istream& operator>>(std::istream& inDev, Array& arr) {
        inDev >> arr.m_size;

        delete[] arr.m_arr;

        if (arr.m_size < 0) {
            arr.m_size = 0;
        }

        arr.m_arr = new T [arr.m_size];

        for (int i = 0; i < arr.m_size; i++) {
            inDev >> arr.m_arr[i];
        }

        return inDev;
    }

    friend std::ostream& operator<<(std::ostream& outDev, Array& arr) {
        for (int i = 0; i < arr.m_size; i++) {
            outDev << arr.m_arr[i] << " ";
        }
        outDev << "\n";

        return outDev;
    }
};

#endif