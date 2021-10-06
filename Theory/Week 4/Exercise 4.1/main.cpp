#include <iostream>
#include "Fraction.h"

int main() {
    //This main() is used to test operators only.

    Fraction f1(1, 2);
    Fraction f2(7, 9);

    Fraction f3 = f1 + f2;
    std::cout << f3 << "\n";

    Fraction f4 = f1 * f3;
    std::cout << f4 << "\n";

    f4 += f2;
    std::cout << f4 << "\n";

    f3 *= f1;
    std::cout << f3 << "\n";

    float f = (float)f4;
    int i = (int)f4;

    std::cout << f << " " << i << "\n"; 

    return 0;
}