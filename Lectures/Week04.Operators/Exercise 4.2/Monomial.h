#ifndef _MONOMIAL_H
#define _MONOMIAL_H

#include <iostream>

class Monomial {
	//class Monimial: a * x^n
private:
	double m_coefficient;
	int m_exponent;

public:
	//default constructor
	Monomial();

	//fully-parameterized constructor
	Monomial(double c, int e);

	//copy constructor
	Monomial(const Monomial& m);

	//The following two operators are arithmetic operators.
	Monomial operator+(const Monomial& m); //the same degree

	Monomial operator*(const Monomial& m);

	//The following six operators are comparison operators.
	bool operator>(Monomial& m);

	bool operator<(Monomial& m);

	bool operator==(Monomial& m);

	bool operator>=(Monomial& m);

	bool operator<=(Monomial& m);

	bool operator!=(Monomial& m);

	//The following three operators are assigning operators.
	Monomial& operator=(Monomial& m);

	Monomial& operator+=(Monomial& m); //the same degree

	Monomial& operator*=(Monomial& m);

	//The following four operators are degree increment and decrement operators.
	Monomial& operator++(); //prefix

	Monomial operator++(int x); //postfix

	Monomial& operator--(); //prefix

	Monomial operator--(int x); //postfix

	//The following operator is derivative operator.
	Monomial operator!();

	//The following operators are input and output operator,
	//they are not operators of this class,
	//so the keyword "friend" is used to access private members.
	friend std::istream& operator>>(std::istream& inDev, Monomial& m);

	friend std::ostream& operator<<(std::ostream& outDev, Monomial& m);
};

#endif
