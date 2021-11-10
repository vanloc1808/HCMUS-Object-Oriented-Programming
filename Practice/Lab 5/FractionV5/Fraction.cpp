#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "Fraction.h"

//default constructor 0/1.
Fraction::Fraction() {
	this->m_numerator = 0;
	this->m_denominator = 1;
}

//constructor with both numerator and denominator.
Fraction::Fraction(int num, int den) {
	this->m_numerator = num;
	if(den != 0) {
		this->m_denominator = den;
	} else {
		//if den == 0, random a value for it, in this case I chosse 1.
		//this can lead to unexpected error.
		this->m_denominator = 1; 
	}
}

//constructor with a given integer, in this case denominator will be 1 -> simplified form.
Fraction::Fraction(int givenInt) {
	this->m_numerator = givenInt;
	this->m_denominator = 1;
}

//copy constructor.
Fraction::Fraction(const Fraction& fr) {
	this->m_numerator = fr.m_numerator;
	this->m_denominator = fr.m_denominator;
}

int Fraction::getNum() {
    return this->m_numerator;
}

int Fraction::getDen() {
    return this->m_denominator;
}

void Fraction::setNum(int n) {
    this->m_numerator = n;
}

void Fraction::setDen(int d) {
    //d == 0 can leads to error.
    if (d != 0) {
        this->m_denominator = d;
    }
}

int findGCD(int a, int b) {
	a = abs(a);
	b = abs(b);

	//swap so that b is always not less than a.
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}

	if (a == 0) {
		return b;
	}

	if (b % a == 0) {
		return a;
	} 
	return findGCD(b % a, a);
}

void Fraction::simplify() {
	int gcd = findGCD(this->m_numerator, this->m_denominator);

	this->m_numerator /= gcd;
	this->m_denominator /= gcd;
}

int Fraction::sign() {
	//nonnegative
	if (1LL * this->m_numerator * this->m_denominator >= 0) {
		return 1;
	} 

	//negative
	return -1;
}

std::string Fraction::toString() {
	std::stringstream ss;
	ss << this->m_numerator << "/" << this->m_denominator;
	return ss.str();
}