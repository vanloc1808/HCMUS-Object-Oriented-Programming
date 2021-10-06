#include <iostream>
#include "Fraction.h"

//default constructor 0/1.
Fraction::Fraction() {
	this->m_numerator = 0;
	this->m_denominator = 1;
}

//constructor with both numerator and denominator.
Fraction::Fraction(int num, int den) {
	this->m_numerator = num;
	this->m_denominator = den;
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

void Fraction::output() {
	if (this->m_numerator == 0 || this->m_denominator == 1) {
		std::cout << this->m_numerator << "\n";
	}
	else {
		std::cout << this->m_numerator << "/" << this->m_denominator << "\n";
	}
}