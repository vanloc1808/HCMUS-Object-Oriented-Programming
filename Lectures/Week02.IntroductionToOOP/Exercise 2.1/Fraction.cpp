#include <iostream>
#include "Fraction.h"

//Function used for input a fraction.
//This function will use 2 temporary variables to save data entered first.
//Than it will compare the entered denominator will 0, if they equal, return FALSE.
//Otherwise, assign these two temporary variables to numerator and denominator of the current fraction and return TRUE.
//Fraction will be simplified just after input.
bool Fraction::input() {
	int tempNumerator;
	int tempDenominator;

	std::cin >> tempNumerator >> tempDenominator;

	//In case the input denominator is zero.
	if (tempDenominator == 0) {
		return false;
	}

	this->numerator = tempNumerator;
	this->denominator = tempDenominator;

	this->simplify();

	return true;
}

//Function used for output a fraction.
void Fraction::output() {
	int numerator = this->numerator;
	int denominator = this->denominator;

	//Special cases: numerator = 0 or denominator = 1;
	if (numerator == 0 || denominator == 1) {
		std::cout << numerator << " ";

		return;
	}

	std::cout << numerator << "/" << denominator << " ";
}

//Function used for getting the value of the numerator.
int Fraction::getNumerator() {
	return this->numerator;
}

//Function used for getting the value of the denominator.
//Assume that the denominator is not 0, because we have checked in the input function above.
int Fraction::getDenominator() {
	return this->denominator;
}

//Function used for assigning a new value for the numerator.
//No conditions required.
void Fraction::assignNumerator(int newNumerator) {
	this->numerator = newNumerator;
}

//Function used for assigning a new value for the denominator.
//If the new denominator is zero, it will return FALSE.
//Otherwise, assign and return TRUE.
bool Fraction::assignDenominator(int newDenominator) {
	//In case the new denominator is zero.
	if (newDenominator == 0) {
		return false;
	}

	this->denominator = newDenominator;

	return true;
}

//Function used for inversing a fraction.
//A new fraction res is initialized to store the result.
//WARNING: if the numerator of this fraction is 0, which means that it cannot be inversed, the fuction will return 0/0
//Therefore, we need to CHECK the result after calling this function.
Fraction Fraction::getInverse() {
	Fraction res;
	res.assignNumerator(0);
	res.assignDenominator(0);

	if (this->numerator == 0) {
		return res;
	}

	int numerator = this->numerator;
	int denominator = this->denominator;

	res.assignNumerator(denominator);
	res.assignDenominator(numerator);

	return res;
}

//Function used for finding greatest common divisor, helps simplify a fraction.
//This function is NOT generalized for other data type because it is only needed in simplifying process.
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

//Function used for simplifying a fraction.
//Divide both numerator and denominator for their greatest commond divisor.
//Return void because it only processes and directly changes the current fraction.
void Fraction::simplify() {
	int gcd = findGCD(this->numerator, this->denominator);

	this->numerator /= gcd;
	this->denominator /= gcd;

	//In case both numerator and denominator is negative, they will be both positive.
	if (this->numerator < 0 && this->denominator < 0) {
		this->numerator /= -1;
		this->denominator /= -1;
	}
}

//Function used for adding a fraction named term to the current fraction.
//Return the result, not change the value of the current fraction.
Fraction Fraction::add(Fraction term) {
	Fraction res;

	//Find numerator and denominator for the sum
	int numerator = this->numerator * term.denominator + this->denominator * term.numerator;
	int denominator = this->denominator * term.denominator;

	res.assignNumerator(numerator);
	res.assignDenominator(denominator);

	//Simplify the result
	res.simplify();

	return res;
}

//Function used for multiplying a fraction named factor to the current fraction.
//Return the result, not change the value of the current fraction.
Fraction Fraction::multiply(Fraction factor) {
	Fraction res;

	//Find numerator and denominator for the sum
	int numerator = this->numerator * factor.numerator;
	int denominator = this->denominator * factor.denominator;

	res.assignNumerator(numerator);
	res.assignDenominator(denominator);

	//Simplify the result
	res.simplify();

	return res;
}

//This is a fraction to get sign of a fraction, helps to compare two fractions.
//Return 0 if the fraction is 0,
//Return 1 if the fraction is positive,
//Return -1 if the fraction is negative.
int getSign(Fraction fraction) {
	//In case the fraction is zero.
	if (fraction.getNumerator() == 0) {
		return 0;
	}

	int numerator = fraction.getNumerator();
	int denominator = fraction.getDenominator();

	//In case one of the two attributes is negative.
	//Because the fraction is simplified after input, there is no case that they are both negative.
	if (numerator < 0 || denominator < 0) {
		return -1;
	}

	return 1;
}

//Function used for comparing the current fraction with another fraction named other.
//Return positive value if the current fraction is greater,
//Return negative value if the current fraction is less,
//Return 0 if they are equal.
int Fraction::compare(Fraction other) {
	int thisSign = getSign(*this);
	int otherSign = getSign(other);

	//The following two if statements process the case that they have different sign.
	if (thisSign > otherSign) {
		return 1;
	}

	if (thisSign < otherSign) {
		return -1;
	}

	return (this->numerator * other.denominator - this->denominator * other.numerator);
}