#include <iostream>
#include <ctime>
#include "TimeV5.h"

int main() {
    GMTTime t;

    std::cout << t.toString(0) << "\n";

    std::cout << t.toString(10) << "\n";

    return 0;
}