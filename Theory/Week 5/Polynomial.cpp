#include <iostream>
#include <climits>
#include "Polynomial.h"

///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//default constructor,
//construct a zero polynomial
Polynomial::Polynomial() {
    this->m_degree = 0;
    this->m_coefficients = new double[1];
    this->m_coefficients[0] = 0;
}

//fully-parameterized constructor with degree and the array of coefficients
//the polynomial looks like below
//P(x) = a[0] * x^n + a[1] * x^(n - 1) + ... + a[n - 1] * x + a[n]
//there are n + 1 coefficients with a n-degree polynomial
//sorted by descending degree
Polynomial::Polynomial(int newDegree, double* newCoefficients) {
    //make sure that the degree is nonnegative
    if(newDegree < 0) {
        newDegree = 0;
    }

    this->m_degree = newDegree;

    //delete the old coefficients
    delete[] this->m_coefficients;

    //allocate the memory
    this->m_coefficients = new double[this->m_degree];

    for (int i = 0; i < this->m_degree; i++) {
        this->m_coefficients[i] = newCoefficients[i];
    }
}

//copy constructor
Polynomial::Polynomial(const Polynomial& p) {
    //in this constructor, we assume that the degree of p is nonnegative
    this->m_degree = p.m_degree;

    //delete the old coefficients
    delete[] this->m_coefficients;

    //allocate the memory
    this->m_coefficients = new double[this->m_degree];

    for(int i = 0; i < this->m_degree; i++) {
        this->m_coefficients[i] = p.m_coefficients[i];
    }
}

//destructor, avoid memory leak
Polynomial::~Polynomial() {
    this->m_degree = 0;
    if(this->m_coefficients) {
        delete[] this->m_coefficients;
    }

    this->m_coefficients = nullptr;
}


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////INFORMATION GETTERS/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//getter for degree
int Polynomial::getDegree() {
    return this->m_degree;
}

//getter for coefficient of a certain degree
//input: an integer i
double Polynomial::getCoefficient(int i) {
    //i is out of bound, can lead to unexpected error
    if (i < 0 || i > this->m_degree) {
        return INT_MIN;
    }

    return this->m_coefficients[this->m_degree - i];
}