#include <iostream>
#include "Fraction.h"

int main() {
    Fraction* f = Fraction::Parse("18/8");

    f->simplify();

    std::cout << f->toString() << "\n";

    delete f;

    f = Fraction::TryParse("18/2/2");

    if (f) {
        std::cout << f->toString() << "\n";

        delete f;
    }

    return 0;
}