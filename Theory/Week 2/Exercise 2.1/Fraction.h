#pragma once

class Fraction {
private:
	int numerator;
	int denominator;

public:
	
	bool input(); //Return false if the denominator is zero!

	void output();

	int getNumerator();

	int getDenominator();

	void assignNumerator(int newNumerator);

	bool assignDenominator(int newDenominator); //Return false if the new denominator is zero!

	Fraction getInverse();

	void simplify();

	Fraction add(Fraction term);

	Fraction multiply(Fraction factor);

	int compare(Fraction other); 
};

//This is a sub-function for finding the greatest common divisor when simplifying a fraction.
//This function is generalized for later usage.
template<class T>
void swapThem(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
