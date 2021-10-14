#ifndef _MONOMIAL_H
#define _MONOMIAL_H

#include <iostream>

class Polynomial {
private:
    int m_degree;
    double* m_coefficients;

public:
    ///////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////

    Polynomial(); //default constructor

    Polynomial(int newDegree, double* newCoefficients); //constructor with given degree and coefficients

    Polynomial(const Polynomial& p); // copy constructor

    ~Polynomial(); //destructor

    ///////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////INFORMATION GETTERS/////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////

    int getDegree(); //getter for degree

    double getCoefficient(int i); //getter for coefficient at a certain degree

    ///////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////JOB PROCESSORS////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////

    bool compare(const Polynomial& p); //compare with another polynomial

    void simplify(); //simplify this polynomial

    double countValue(double x); //count value of polynomial at a certain point

    Polynomial& derivative(); //get the derivative of this polynomial

    Polynomial& integral(); //get the integral of this polynomial

    ///////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////OPERATORS/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////

    //ARITHMETIC OPERATORS//

    Polynomial operator+(const Polynomial& p); //addition operator

    Polynomial& operator-(const Polynomial& p); //substraction operator

    Polynomial& operator*(const Polynomial& p); //multiplication operator

    Polynomial& operator/(const Polynomial& p); //division operator

    Polynomial& operator=(const Polynomial& p); //assigning operator

    //COMPARISION OPERATORS//

    bool operator>(const Polynomial& p); //greater operator

    bool operator<(const Polynomial& p); //less operator

    bool operator==(const Polynomial& p); //equal operator

    bool operator>=(const Polynomial& p); //greater or equal operator

    bool operator<=(const Polynomial& p); //less or equal operator

    bool operator!=(const Polynomial& p); //not equal operator

    //CALCULUS OPERATORS//

    Polynomial& operator!(); //derivative operator

    Polynomial& operator~(); //integral operator

    //INPUT AND OUTPUT OPERATORS//
    friend std::istream& operator>>(std::istream inDev, Polynomial& p); //input operator

    friend std::ostream& operator<<(std::ostream outDev, Polynomial& p); //output operator
};

#endif
