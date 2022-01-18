#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
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
    //delete[] this->m_coefficients;

    //allocate the memory
    this->m_coefficients = new double[this->m_degree + 1];

    for (int i = 0; i <= this->m_degree; i++) {
        this->m_coefficients[i] = newCoefficients[i];
    }
}

//copy constructor
Polynomial::Polynomial(const Polynomial& p) {
    //in this constructor, we assume that the degree of p is nonnegative
    this->m_degree = p.m_degree;

    //delete the old coefficients
    //delete[] this->m_coefficients;

    //allocate the memory
    this->m_coefficients = new double[this->m_degree + 1];

    for(int i = 0; i <= this->m_degree; i++) {
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

///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////JOB PROCESSORS////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//compare *this with p
//output: 1 if *this > p,
//output 0 if *this == p.
//and output -1 if *this < p.
//prioritize degree, of course.
bool Polynomial::compare(const Polynomial& p) {
    if (this->m_degree > p.m_degree) {
        return 1;
    }

    if (this->m_degree < p.m_degree) {
        return -1;
    }

    int deg = this->m_degree;
    double* thisCoeff = this->m_coefficients;
    double* pCoeff = p.m_coefficients;

    for (int i = 0; i <= deg; i++) {
        if (thisCoeff[i] > pCoeff[i]) {
            return 1;
        } 

        if (thisCoeff[i] < pCoeff[i]) {
            return -1;
        }
    }

    return 0;
}

//simplify if the most significant coefficient == 0
void Polynomial::simplify() {
    int degree = this->m_degree;
    double* curCoeff = new double[degree + 1];

    for (int i = 0; i <= degree; i++) {
        curCoeff[i] = this->m_coefficients[i];
    }

    int idx = 0;

    while(curCoeff[idx] == 0) {
        degree--;
        idx++;
    }

    delete[]this->m_coefficients;
    this->m_coefficients = new double[degree + 1];

    for (int i = idx; i <= degree; i++) {
        this->m_coefficients[i - idx] = curCoeff[i];
    }
    
    this->m_degree = degree;

    //delete[]curCoeff;
    //curCoeff = nullptr;
}

//count the value of this polynomial at a certain point
double Polynomial::countValue(double x) {
    double ans = 0;
    double* coeff = this->m_coefficients;

    for (int i = 0; i <= this->m_degree; i++) {
        ans += coeff[i] * pow(x, this->m_degree - i);
    }

    return ans;
}

//get the derivative of this polynomial
//follow the formula: (a * x^n)' = a * n * x^(n - 1)
Polynomial& Polynomial::derivative() {
    int degree = this->m_degree - 1;
    double* coeff = new double[degree + 1];

    for (int i = 0; i <= degree; i++) {
        coeff[i] = this->m_coefficients[i] * (this->m_degree - i);
    }

    

    Polynomial ans(degree, coeff);

    delete[]coeff;
    coeff = nullptr;

    return ans;
}

//get the integral of this polynomial
//follow the formula: S(a * x^n) = a / (n + 1) * x^(n + 1)
//we get the "primitive" integral, which means that the constant C = 0
Polynomial& Polynomial::integral() {
    int degree = this->m_degree + 1;
    double* coeff = new double[degree + 1];

    for (int i = 0; i < degree; i++) {
        coeff[i] = this->m_coefficients[i] / (this->m_degree - i + 1);
    }
    coeff[degree] = 0;

   Polynomial ans(degree, coeff);

    delete[]coeff;
    coeff = nullptr;

    return ans;
}