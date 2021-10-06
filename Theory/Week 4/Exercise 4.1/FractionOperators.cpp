#include <iostream>
#include "Fraction.h"

//operator + for Fraction class
// a/b + c/d = (a * d + b * c)/(b * d)
//then simplify it.
Fraction Fraction::operator+(const Fraction& fr) {
    Fraction res;

    res.m_numerator = this->m_numerator * fr.m_denominator + this->m_denominator * fr.m_numerator;
    res.m_denominator = this->m_denominator * fr.m_denominator;

    res.simplify();

    return res;
}

//operator * for Fraction class
// a/b * c/d = (a * c)/(b * d)
// then simplify it.
Fraction Fraction::operator*(const Fraction& fr) {
    Fraction res;

    res.m_numerator = this->m_numerator * fr.m_numerator;
    res.m_denominator = this->m_denominator * fr.m_denominator;

    res.simplify();

    return res;
}

bool Fraction::operator>(Fraction& fr) {
    int signThis = this->sign();
    int signFr = fr.sign();

    //this is nonnegative, fr is negative
    if (signThis > signFr) {
        return true;
    }

    //this is negative, fr is nonnegative

    if (signThis < signFr) {
        return false;
    }

    //they have the same size

    int chk = 1LL * this->m_numerator * fr.m_denominator - this->m_denominator * fr.m_numerator;

    if (chk > 0) {
        return true;
    }

    return false;
}

bool Fraction::operator<(Fraction& fr) {
    int signThis = this->sign();
    int signFr = fr.sign();

    //this is nonnegative, fr is negative
    if (signThis > signFr) {
        return false;
    }

    //this is negative, fr is nonnegative

    if (signThis < signFr) {
        return true;
    }

    //they have the same size

    int chk = 1LL * this->m_numerator * fr.m_denominator - this->m_denominator * fr.m_numerator;

    if (chk < 0) {
        return true;
    }

    return false;
}

bool Fraction::operator==(Fraction& fr){
    this->simplify();
    fr.simplify();

    //compare 2 simplified fractions.
    if (this->m_numerator == fr.m_numerator) {
        if (this->m_denominator == fr.m_denominator) {
            return true;
        }

        return false;
    }

    return false;
}

//The following three operators: >=, <=, != is written using the previous operators <, >, ==.
bool Fraction::operator>=(Fraction& fr) {
    if (*this < fr) {
        return false;
    }

    return true;
}

bool Fraction::operator<=(Fraction& fr) {
    if (*this > fr) {
        return false;
    }

    return true;
}

bool Fraction::operator!=(Fraction& fr) {
    if (*this == fr) {
        return false;
    }

    return true;
}

//The following operators return *this to make it the same as built-in types.
//In these operators, we will assume that the fr is a valid fraction.

//Assignment operator: assign a fraction with another one.
Fraction& Fraction::operator=(Fraction& fr) {
    fr.simplify(); //simplify before assigning

    this->m_numerator = fr.m_numerator;
    this->m_denominator = fr.m_denominator;

    return *this;
}

//Assignment operator: assign a fraction with an integer, 
//the denominator will be 1.
Fraction& Fraction::operator=(int n) {
    this->m_numerator = n;
    this->m_denominator = 1;

    return *this;
}

//+= operator with a fraction
Fraction& Fraction::operator+=(Fraction& fr) {
    fr.simplify(); //simplify before processing

    this->m_numerator = this->m_numerator * fr.m_denominator + this->m_denominator * fr.m_numerator;
    this->m_denominator = this->m_denominator * fr.m_denominator;

    this->simplify(); //simplify the result

    return *this;
}

//+= operator with an integer
Fraction& Fraction::operator+=(int n) {
    this->m_numerator += n * this->m_denominator;

    this->simplify();

    return *this; //simplify the result
}

//*= operator with a fraction
Fraction& Fraction::operator*=(Fraction& fr) {
    this->m_numerator *= fr.m_numerator;
    this->m_denominator *= fr.m_denominator;

    this->simplify(); //simplify the result

    return *this;
}

//*= operator with an integer
// a/b * n = (a * n)/b
Fraction& Fraction::operator*=(int n) {
    this->m_numerator *= n;

    this->simplify(); //simplify the result

    return *this;
}

//operator ++ to be a prefix
Fraction& Fraction::operator++() {
    *this += 1; //use the operator +=

    this->simplify(); //simplify the result

    return *this;
}

//operator ++ to be postfix,
//parameter x is only used to make the function signature differs from the prefix
//The postfix operators can only return value, not reference.
Fraction Fraction::operator++(int x) {
    Fraction temp = *this;

    *this += 1;

    this->simplify(); //simplify the result

    return temp;
}

//operator ++ to be a postfix
Fraction& Fraction::operator--() {
    *this += -1; //use the operator +=

    this->simplify(); //simplify the result

    return *this;
}

//operator +== to be postfix,
//parameter x is only used to make the function signature differs from the prefix
//The postfix operators can only return value, not reference.
Fraction Fraction::operator--(int x) {
    Fraction temp = *this;

    *this += -1;

    this->simplify(); //simplify the result

    return temp;
}

//The operator to cast a fraction into a float,
//this will NOT change the fraction,
//therefore it returns value only.
Fraction::operator float() const {
    float res = (1.00F * this->m_numerator) / this->m_denominator;

    return res;
}

//The operator to cast a fraction into an integer,
//this will NOT change the fraction,
//therefore it returns value only.
Fraction::operator int() const {
    int res = this->m_numerator / this->m_denominator;

    return res;
}

//The operator >> used to input a fraction.
std::istream& operator>>(std::istream& inDev, Fraction& fr) {
    int num, den;
    inDev >> num >> den;

    fr.m_numerator = num;
    if (den != 0) {
        fr.m_denominator = den;
    } else {
        fr.m_denominator = 1; //den == 0 can leads to wrong answer, because it is edited to 1.
    }

    return inDev;
}

//The operator << used to output a fraction.
//In a/b, if a == 0 or b == 1, only print a.
std::ostream& operator<<(std::ostream& outDev, const Fraction& fr) {
    int num = fr.m_numerator;
    int den = fr.m_denominator;
    if (num == 0 || den == 1) {
        outDev << num;
    } else {
        outDev << num << "/" << den;
    }

    return outDev;
}