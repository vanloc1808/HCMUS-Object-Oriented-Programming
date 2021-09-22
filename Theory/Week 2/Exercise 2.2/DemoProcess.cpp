//This file contains the file for feature demo process.
//Function used in this file describe in the Monomial.cpp

#include <iostream>
#include "DemoProcess.h"
#include "Monomial.h"

using namespace std;

void showMenu() {
	cout << "Here is the menu of the program.\n";
	cout << "1. Get the coefficient.\n";
	cout << "2. Get the exponent.\n";
	cout << "3. Assign a new value for coefficient.\n";
	cout << "4. Assign a new value for the exponent.\n";
	cout << "5. Calculate the value.\n";
	cout << "6. General form of the derivative.\n";
	cout << "7. Add a monomial with the same degree to this monomial.\n";
	cout << "8. Multiply a monomial to this monomial.\n";
	cout << "9. Compare this monomial with another monomial.\n";
}

void inputNoti() {
	cout << "Enter the coefficient and exponent respectively, seperated by a space.\n";
}

void getCoefficientProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	cout << "The coefficient is: " << mono.getCoefficient() << "\n";
}

void getExponentProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	cout << "The exponent is: " << mono.getExponent() << "\n";
}

void newCoefficientProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	int newCoefficient = 0;
	cout << "Enter new coefficient: ";
	cin >> newCoefficient;

	mono.assignCoefficient(newCoefficient);

	cout << "After changin coefficient: ";
	mono.output();
	cout << "\n";
}

void newExponentProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	int newExponent = 0;
	cout << "Enter new exponent: ";
	cin >> newExponent;

	mono.assignExponent(newExponent);

	cout << "After changin exponent: ";
	mono.output();
	cout << "\n";
}

//This function calculates both the value of the monomial and the derivative.
void calculateProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	double value = 0;
	cout << "Enter the value of x: ";
	cin >> value;

	cout << "The value of the monomial at x is : " << mono.calculate(value) << "\n";
	cout << "The value of the derivative of the monomial at x is: " << mono.calculateDerivative(value) << "\n";
}

void generalDerivativeProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	Monomial derivative = mono.derivative();

	cout << "The general form of the derivate of this monomial is: ";
	derivative.output();
	cout << "\n";
}

void addProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	double termCoefficient = 0;
	cout << "Enter the coefficient of the monomial (with same degree) needs adding to this monomial: ";
	cin >> termCoefficient;

	Monomial res = mono.add(termCoefficient);

	cout << "The result is: ";
	res.output();
	cout << "\n";
}

void multiplyProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	Monomial factor;
	cout << "Enter the monomial needs adding to this monomial: ";
	inputNoti();
	factor.input();

	Monomial res = mono.multiply(factor);
	
	cout << "The result is: ";
	res.output();
	cout << "\n";
}

void compareProcess() {
	Monomial mono;

	inputNoti();
	mono.input();

	Monomial other;
	cout << "Enter the monomial needs comparing to this monomial: ";
	inputNoti();
	other.input();

	int compareResult = mono.compare(other);
	mono.output();
	if (compareResult == 1) {
		cout << " > ";
	}
	else if (compareResult == -1) {
		cout << " < ";
	}
	else {
		cout << " = ";
	}
	other.output();
	
}
