#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Process.h"

//This fuction simplifies a fraction.
//Just divide its numerator and denominator by their gcd.
Fraction simplifyFraction(Fraction& p) {
	int gcdOfTwo = findGCD(p.numerator, p.denominator);

	p.numerator /= gcdOfTwo;
	p.denominator /= gcdOfTwo;

	return p;
}

std::istream& operator>> (std::istream& istr, Fraction& frac) {
	istr >> frac.numerator >> frac.denominator;

	simplifyFraction(frac);

	return istr;
}

std::ostream& operator<< (std::ostream& ostr, Fraction frac) {
	if (frac.numerator == 0 || frac.denominator == 1) {
		ostr << frac.numerator;

		return ostr;
	}

	ostr << frac.numerator << "/" << frac.denominator;

	return ostr;
}

//This operator returns true if frac1 > frac2.
//The fraction a/b is greater than the fraction c/d when a * d > c * b
bool operator> (Fraction frac1, Fraction frac2) {
	return frac1.numerator * frac2.denominator > frac1.denominator * frac2.numerator;
}

//This operator returns true if frac1 < frac2.
//It's able to reuse the operator > written above.
bool operator< (Fraction frac1, Fraction frac2) {
	return (frac2 > frac1);
}

//This function was not generalized for any data types because in this program, it is be used only for simplyfying a fraction.
//It returns the greatest common divisor of two integers a and b.
int findGCD(int a, int b) {
	a = abs(a);
	b = abs(b);

	if (a > b) {
		swapThem(a, b);
	}

	if (a == 0) {
		return b;
	}

	if (b % a == 0) {
		return a;
	}
	return findGCD(b % a, a);
}
