#include <iostream>
#include "Fraction.h"

template<class T>
T Max(T a, T b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int ai = 1, bi = 9;
    std::cout << "Int: maximum number of " << ai << " and " << bi << " is " << Max(ai, bi) << "\n";

    float af = 1.90, bf = 1.92;
    std::cout << "Float: maximum number of " << af << " and " << bf << " is " << Max(af, bf) << "\n";

    char ac = 'a', bc = 'b';
    std::cout << "Char: maximum of " << ac << " and " << bc << " is " << Max(ac, bc) << "\n";

    Fraction afr(1, 2), bfr(2, 3);
    std::cout << "Fraction: maximum of " << afr << " and " << bfr << " is " << Max(afr, bfr) << "\n";

    return 0;
}