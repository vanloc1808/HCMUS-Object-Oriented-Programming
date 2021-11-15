#include <iostream>
#include <ctime>
#include "DateV5.h"

int main() {
    Date dcur;
    std::cout << dcur.toString() << "\n";

    Date d1(2002, 9, 20);
    std::cout << d1.toString() << "\n";
    std::cout << d1 << "\n";
    std::cin >> d1;
    std::cout << d1 << "\n";

    Date d2(2021, 2, 30);
    std::cin >> d2;
    std::cout << d2 << "\n";
}