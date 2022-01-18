#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction();

	Fraction(int num, int den);

	Fraction(int givenInt);

	Fraction(const Fraction& fr);

	void simplify();

	int sign(); //determine if a fraction is negative or not.

	//The following two operators are arithmetic operators.
	Fraction operator+(const Fraction& fr);

	Fraction operator*(const Fraction& fr);

	//The following six operators are comparison operators.
	//The fr is passed-by-value because it can be simplified,
	//so that the comparison will be easier.
	bool operator>(Fraction& fr);

	bool operator<(Fraction& fr);

	bool operator==(Fraction& fr);

	bool operator>=(Fraction& fr);

	bool operator<=(Fraction& fr);

	bool operator!=(Fraction& fr);

	//The following four operators are assigning operators.
	Fraction& operator=(Fraction& fr);

	Fraction& operator=(int n);

	Fraction& operator+=(Fraction& fr);

	Fraction& operator+=(int n);

	Fraction& operator*=(Fraction& fr);

	Fraction& operator*=(int n);

	//The following four operators are increment and decrement operators.
	Fraction& operator++(); //prefix

	Fraction operator++(int x); //postfix 

	Fraction& operator--(); //prefix

	Fraction operator--(int x); //postfix

	//The following two operators used to cast into another data types,
	//I googled and found that they said we have to used the keyword "explicit" for this type of operators.
	//Source: https://daynhauhoc.com/t/chuyen-kieu-cua-doi-tuong-nap-chong-toan-tu-ten-class-trong-c/34605/2
	explicit operator float() const;

	explicit operator int() const;

	//The following two operators used to input and output a fractions.
	//Because they cannot be an operator of a class, we have to use the keyword "friend",
	//to access private members.
	friend std::istream& operator>>(std::istream& inDev, Fraction& fr);

	friend std::ostream& operator<<(std::ostream& outDev, const Fraction& fr);
};

//This function is used to find the greatest common divisor of two integers,
//in this header we use it as a sub-function to simplify a fraction.
int findGCD(int a, int b);

#endif // !_FRACTION_H