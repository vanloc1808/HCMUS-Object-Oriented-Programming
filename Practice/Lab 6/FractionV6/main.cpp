#include <iostream>
#include "Fraction.h"

int main() {
    Fraction f(18, 8);
    f.simplify();
    std::cout << f.toString() << "\n";
}