// Exercise 3.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"

int Fraction::number = 0;


int main()
{
    Fraction fr1;
    Fraction fr2(3);
    Fraction fr3(2, 9);

    std::cout << "The number of fractions created is: " << Fraction::number << "\n";
}
