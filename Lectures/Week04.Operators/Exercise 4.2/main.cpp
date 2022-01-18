#include <iostream>
#include "Monomial.h"

int main() {
    Monomial m1(4, 5);
    Monomial m2(7, 5);

    Monomial m3 = m1 + m2;
    Monomial m4 = m1 * m2;
    Monomial m5 = !m4;

    std::cout << m1 << "\n";
    std::cout << m2 << "\n";
    std::cout << m3 << "\n";
    std::cout << m4 << "\n";
    std::cout << m5 << "\n";
    
    return 0;
}