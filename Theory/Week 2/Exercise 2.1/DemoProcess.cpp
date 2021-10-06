//This file contains the file for feature demo process.
//Function used in this file describe in the Fraction.cpp

#include <iostream>
#include "DemoProcess.h"
#include "Fraction.h"

using namespace std;

void showMenu() {
	cout << "Here is the menu of the program.\n";
	cout << "1. Get the numerator.\n";
	cout << "2. Get the denominator.\n";
	cout << "3. Assign a new value for numerator.\n";
	cout << "4. Assign a new value for the denominator.\n";
	cout << "5. Get the inversed fraction.\n";
	cout << "6. Simplify a fraction.\n";
	cout << "7. Add a fraction to this fraction.\n";
	cout << "8. Multiply a fraction to this fraction.\n";
	cout << "9. Compare this fraction with another fraction.\n";
}


void inputNoti() {
	cout << "Enter the numerator and denominator respectively, seperated by a space.\n";
	cout << "The fraction will be simplified after being entered.\n";
}

void getNumeratorProcess() {
	Fraction frac;

	inputNoti();
	frac.input();

	cout << "The numerator is: " << frac.getNumerator() << "\n";
}

void getDenominatorProcess() {
	Fraction frac;

	inputNoti();
	frac.input();

	cout << "The denominator is: " << frac.getDenominator() << "\n";
}

void newNumeratorProcess() {
	Fraction frac;

	inputNoti();
	frac.input();

	int newNumerator = 0;
	cout << "Enter new numerator: ";
	cin >> newNumerator;

	frac.assignNumerator(newNumerator);

	cout << "After simplifying and changing numerator: ";
	frac.output();
	cout << "\n";
}

void newDenominatorProcess() {
	Fraction frac;

	inputNoti();
	frac.input();

	int newDenominator;
	cout << "Enter new denominator: ";
	cin >> newDenominator;

	if (!frac.assignDenominator(newDenominator)) {
		"The denominator cannot be zero.\n";
		return;
	}

	cout << "After simplifying and changing denominator: ";
	frac.output();
	cout << "\n";
}

void inverseProcess() {
	Fraction frac;

	inputNoti();
	frac.input();

	Fraction inverse = frac.getInverse();

	cout << "The inverse function of ";
	frac.output();
	cout << " is: ";
	inverse.output();
	cout << "\n";
}

void simplifyProcess() {
	Fraction frac;

	inputNoti();
	frac.input();

	cout << "After simplifying: ";
	frac.output();
	cout << "\n";
}

void addProcess() {
	Fraction frac;

	cout << "Enter the current fraction: ";
	inputNoti();
	frac.input();

	Fraction term;

	cout << "Enter the fraction needed adding to the current fraction: ";
	inputNoti();
	term.input();

	Fraction res = frac.add(term);
	cout << "The result is: ";
	res.output();
	cout << "\n";
}

void multiplyProcess() {
	Fraction frac;

	cout << "Enter the current fraction: ";
	inputNoti();
	frac.input();

	Fraction factor;

	cout << "Enter the fraction needed multiplying to the current fraction: ";
	inputNoti();
	factor.input();

	Fraction res = frac.multiply(factor);
	cout << "The result is: ";
	res.output();
	cout << "\n";
}

void compareProcess() {
	Fraction frac;

	cout << "Enter the current fraction: ";
	inputNoti();
	frac.input();

	Fraction other;

	cout << "Enter the fraction needed comparing with the current fraction: ";
	inputNoti();
	other.input();

	int res = frac.compare(other);

	frac.output();
	if (res < 0) {
		cout << " < ";
	}
	else if (res > 0) {
		cout << " > ";
	}
	else {
		cout << " = ";
	}
	other.output();
	cout << "\n";
}