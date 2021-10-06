#include <iostream>
#include "Monomial.h"

//default constructor
//initialized with 0 * x^0
Monomial::Monomial() {
    this->m_coefficient = 0;
    this->m_exponent = 0;
}

//fully-parameterized constructor
Monomial::Monomial(double c, int e) {
    this->m_coefficient = c;
    this->m_exponent = e;
}

//copy constructor
Monomial::Monomial(const Monomial& m) {
    this->m_coefficient = m.m_coefficient;
    this->m_exponent = m.m_exponent;
}

Monomial Monomial::operator+(const Monomial& m) {
    //if they have different degrees, do nothing,
    //this can lead to unexpected error.
    //else if the coefficient of m is zero, do nothing too.
    if (m.m_coefficient == 0 || this->m_exponent != m.m_exponent) {
        return *this; 
    }

    //if they have the same degree
    Monomial res = *this;

    res.m_coefficient += m.m_coefficient;

    return res;
}

//operator * for monomials
//a * x^b * c * x^d = (a * c) * x^(b + d)
//maybe overflow happens.
Monomial Monomial::operator*(const Monomial& m) {
    Monomial res = *this;

    res.m_coefficient *= m.m_coefficient;
    res.m_exponent += m.m_exponent;

    return res;
}

//The following six operators are comparison operators.

//operator >
//prioritize the exponent, then coefficient
bool Monomial::operator>(Monomial& m) {
    //if this have the larger exponent.
    if (this->m_exponent > m.m_exponent) {
        return true;
    }

    //if they have the same exponent.
    if (this->m_exponent == m.m_exponent) {
        if (this->m_coefficient > m.m_coefficient) {
            return true;
        }

        return false;
    }

    //if the exponent of this is smaller.
    return false;
}

//operator <
//prioritize the exponent, then coefficient
bool Monomial::operator<(Monomial& m) {
    //if the exponent of this is smaller.
    if (this->m_exponent < m.m_exponent) {
        return true;
    }

    //if they have the same exponent.
    if (this->m_exponent == m.m_exponent) {
        if (this->m_coefficient < m.m_coefficient) {
            return true;
        }

        return false;
    }

    //if the exponent of this is larger.
    return false;
}

//operator ==
//two monomials are equal if they are both zeros,
//or they have the same exponent and the same coefficient
bool Monomial::operator==(Monomial& m) {
    if (this->m_coefficient == 0 && m.m_coefficient == 0) {
        return true;
    }

    if (this->m_coefficient == m.m_coefficient && this->m_exponent == m.m_exponent) {
        return true;
    }

    return false;
}

//In the following three operators, >=, <= and !=, 
//we will use the three previous operators to define.

bool Monomial::operator>=(Monomial& m) {
    if (*this < m) {
        return false;
    }

    return true;
}

bool Monomial::operator<=(Monomial& m) {
    if (*this > m) {
        return false;
    }

    return true;
}

bool Monomial::operator!=(Monomial& m) {
    if (*this == m) {
        return false;
    }

    return true;
}

//The following three operators are assigning operators.
//They return *this type Monomial& to be the same as built-in types.

//operator =
Monomial& Monomial::operator=(Monomial& m) {
    this->m_coefficient = m.m_coefficient;
    this->m_exponent = m.m_exponent;

    return *this;
}

//operator += with the same degree
//different degree can lead to unexpected error
Monomial& Monomial::operator+=(Monomial& m) {
    if (this->m_exponent != m.m_exponent) {
        return *this;
    }

    this->m_coefficient += m.m_coefficient;

    return *this;
}

//operator *= 
//no conditions required
Monomial& Monomial::operator*=(Monomial& m) {
    this->m_coefficient *= m.m_coefficient;
    this->m_exponent += m.m_exponent;

    return *this;
}

//The following four operators are degree increment and decrement operators.
//Two postfix operators cannot be return by reference, 
//return by value only.
Monomial& Monomial::operator++() { //prefix 
    this->m_exponent++;

    return *this;
} 

Monomial Monomial::operator++(int x) { //postfix 
    Monomial temp = *this;

    this->m_exponent++;

    return *this;
}

Monomial& Monomial::operator--() { //prefix 
    this->m_exponent--;

    return *this;
} 

Monomial Monomial::operator--(int x) {//postfix 
    Monomial temp = *this;

    this->m_exponent--;

    return *this;
}

//The operator ! is used to get the derivative of a monomial.
//(a * x^b)' = ab * x^(b - 1)
//this returns value only, and does not change the initial variable.
Monomial Monomial::operator!() {
    Monomial res = *this;

    res.m_coefficient *= this->m_exponent;
    res.m_exponent--;

    return res;
}

//The following operators are input and output operator,
//they are not operators of Monomial class,
//so the keyword "friend" is used to access private members.
std::istream& operator>>(std::istream& inDev, Monomial& m) {
    inDev >> m.m_coefficient >> m.m_exponent;

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, Monomial& m) {
    outDev << m.m_coefficient << " * x^" << m.m_exponent;

    return outDev; 
}
