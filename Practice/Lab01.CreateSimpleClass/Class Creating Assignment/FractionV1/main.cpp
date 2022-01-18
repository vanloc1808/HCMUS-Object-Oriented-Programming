#include <iostream>
#include "Fraction.h"

int main() {
    Fraction f1(1, 2);

    f1.output();
    std::cout << "\n";

    int num = f1.getNum(); 
    int den = f1.getDen();
    std::cout << "Numerator: " << num << "\n";
    std::cout << "Denominator: " << den << "\n";

    f1.setNum(9);
    f1.setDen(20);
    f1.output();
    std::cout << "\n";
}