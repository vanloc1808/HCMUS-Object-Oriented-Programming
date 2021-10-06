#include <iostream>
#include "Fraction.h"

int main() {
	//use default constructor.
	Fraction fr1;

	//use fully-parameterized constructor.
	Fraction fr2(1, 3);

	//use singly-parameterized constructor.
	Fraction fr3(4);

	//use copy constructor.
	Fraction fr4(fr2);

	fr1.output();
	fr2.output();
	fr3.output();
	fr4.output();

	return 0;
}