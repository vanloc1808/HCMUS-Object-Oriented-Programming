#include <iostream>
#include "Process.h"

using namespace std;

int main()
{
    cout << "Exercise 1.3. Write a program to sort an array of integers/fractions/arbitrary data types,\n";
    cout << "in the increasing, decreasing or arbitrary order.\n";
    cout << "The result after sorting will be immediately shown on the console.\n";
    cout << "For example, we will sort an array of integers in the increasing order.\n";
    int* intArray = NULL;
    int intArraySize = 0;
    processFunction(intArray, intArraySize, isLess);
    cout << "Another example, we will sort an array of fractions in the decreasing order.\n";
    cout << "Guide to input a fraction: input its numerator, followed by its denominator, seperated by a space only.\n";
    cout << "The fraction will be automatically simplified.\n";
    Fraction* fracArray = NULL;
    int fracArraySize = 0;
    processFunction(fracArray, fracArraySize, isGreater);
    cout << "Then, you can test with other data types. ^_^\n";
    
}

