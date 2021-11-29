#include <iostream>
#include "Fraction.h"

int main() {
    Fraction f1(1, 2);
    std::cout << "First fraction: " << f1.toString() << "\n";

    Fraction f2(3, 4);
    std::cout << "Second fraction: " << f2.toString() << "\n";

    Fraction fsum = f1 + f2;
    std::cout << "Sum: " << fsum.toString() << "\n";

    Fraction fdiff = f1 - f2;
    std::cout << "Difference: " << fdiff.toString() << "\n";

    Fraction fprod = f1 * f2;
    std::cout << "Product: " << fprod.toString() << "\n";

    Fraction fquot = f1 / f2;
    std::cout << "Quotient: " << fquot.toString() << "\n";

    return 0;
}