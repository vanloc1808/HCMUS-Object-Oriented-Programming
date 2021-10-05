#include <iostream>
#include "Fraction.h"

//default initialization of the fraction is zero, 0/1.
Fraction::Fraction() {
    this->_num = 0;
    this->_den = 1;
}

Fraction::Fraction(int n, int d)
{
    this->_num = n;
    if (d != 0) {
        this->_den = d;
    } else {
        this->_den = 1; //can lead to unexpected error
    }
}

//initialize the fraction with an integer, the denominator is 1.
Fraction::Fraction(int x) {
    this->_num = x;
    this->_den = 1;
}

//in this copy constructor, we will assume that fr is a valid fraction.
Fraction::Fraction(const Fraction& fr) {
    this->_num = fr._num;
    this->_den = fr._den;
}

int Fraction::getNum() {
    return this->_num;
}

int Fraction::getDen() {
    return this->_den;
}

void Fraction::setNum(int n) {
    this->_num = n;
}

void Fraction::setDen(int d) {
    //d == 0 can leads to error.
    if (d != 0) {
        this->_den = d;
    }
}

void Fraction::output() {
    if (this->_num == 0 || this->_den == 1) {
        std::cout << this->_num;
    } else {
        std::cout << this->_num << "/" << this->_den;
    }
}