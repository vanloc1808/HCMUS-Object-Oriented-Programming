#include <iostream>
#include <ctime>
#include "TimeV5.h"

int main() {
    Time tcur;
    std::cout << tcur.toString() << "\n";

    Time t1(1, 2, 3);
    std::cout << t1.toString() << "\n";

    Time t2(25, 100, 4);
}