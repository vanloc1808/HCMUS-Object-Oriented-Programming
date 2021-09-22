#pragma once

class Monomial {
private:
	double coefficient;
	int exponent;
public:
	void input();
	
	void output();

	double getCoefficient();

	int getExponent();

	void assignCoefficient(double newCoefficient);

	void assignExponent(int newExponent);

	double calculate(double x);

	Monomial derivative();

	double calculateDerivative(double x);

	Monomial add(double term); //same degree

	Monomial multiply(Monomial factor);

	int compare(Monomial other);
};
