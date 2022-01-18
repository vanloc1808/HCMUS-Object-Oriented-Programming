#include <iostream>
#include "Fraction.h"

int main() {
    Fraction f(0, 1);
    std::vector<Fraction> v = f.generateVector();

    std::cout << "Vector size: " << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i].toString() << "\n";
    }

    f.getPosition(v);

    return 0;
}