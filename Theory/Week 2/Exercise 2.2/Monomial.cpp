#include <iostream>
#include <cmath>
#include "Monomial.h"

const double EPSILON = 1e-6;

//Function used to input a monomial.
//Enter the coefficient and the exponent respectively.
void Monomial::input() {
	std::cin >> this->coefficient >> this->exponent;
}

//Function used to output a monomial.
//Format: a * (x ^ b).
void Monomial::output() {
	//Special case: coefficient = 0 or exponent = 0
	if (fabs(this->coefficient) <= EPSILON || this->exponent == 0) {
		std::cout << this->coefficient;
		
		return;
	}

	//Special case: coefficient = 1
	if (fabs(this->coefficient - 1) <= EPSILON) {
		std::cout << "x ^ " << this->exponent;

		return;
	}

	std::cout << this->coefficient << " * (x ^ " << this->exponent << ")";
}

//Function used to get the value of a monomial's coefficient.
double Monomial::getCoefficient() {
	return this->coefficient;
}

//Function used to get the value of a monomial's exponent.
int Monomial::getExponent() {
	return this->exponent;
}

//Function used to replace the current coefficient by another one.
void Monomial::assignCoefficient(double newCoefficient) {
	this->coefficient = newCoefficient;
}

//Function used to replace the current exponent by another one.
void Monomial::assignExponent(int newExponent) {
	this->exponent = newExponent;
}

//Function used to calculate the value of a monomial at one point.
//Just replace the value of x into formula.
double Monomial::calculate(double x) {
	double res = this->coefficient * ((pow(x, this->exponent)));
	return res;
}

//Function used to calculate the general form of the derivative of a monomial.
//Formula: (a * x ^ n )' = a * n * (x ^ (n - 1)).
Monomial Monomial::derivative() {
	Monomial res;
	res.coefficient = this->coefficient * this->exponent;
	res.exponent = this->exponent - 1;
	return res;
}

//Function used to calculate the value of derivative at a specific point.
//Just replace the value of x into the general form of derivative.
double Monomial::calculateDerivative(double x) {
	Monomial diff = this->derivative();
	double res = diff.calculate(x);
	return res;
}

//Function used to add another monomial with the same degree to the current monomial.
//Just sum up the coefficient.
//Therefore, we don't need the whole monomial, we only need the term needs adding to the coefficient.
Monomial Monomial::add(double term) {
	Monomial res;
	res.coefficient = this->coefficient + term;
	res.exponent = this->exponent;
	return res;
}

//Function used to multiply another monomial to the current one.
//We need to multiply the coefficients, and sum up the exponent.
//Formula: ax^b * cx^d = (a * c) x ^ (b + d)
Monomial Monomial::multiply(Monomial factor) {
	Monomial res;
	res.coefficient = this->coefficient * factor.coefficient;
	res.exponent = this->exponent + factor.exponent;
	return res;
}

//Function used to compare the current monomial with another one.
//We prioritize the exponent first, followed by the coefficient.
//Return 1 if the current monomial is greater,
//Return -1 if the current monomials is less,
//Return 0 if they are equal.
//Because this is double type, it is not absolute.
int  Monomial::compare(Monomial other) {
	if (this->exponent > other.exponent) {
		return 1;
	} 

	if (this->exponent < other.exponent) {
		return -1;
	}

	//Because this is double type, we shouldn't use the operator == to compare, but we need an epsilon small enough.
	double coeffDifference = this->exponent - other.exponent;
	if (fabs(coeffDifference) <= EPSILON) {
		return 0;
	}

	if (coeffDifference > EPSILON) {
		return 1;
	}

	return -1;
}