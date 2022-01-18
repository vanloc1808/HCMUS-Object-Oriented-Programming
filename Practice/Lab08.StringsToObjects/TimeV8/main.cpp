#include <iostream>
#include <ctime>
#include "TimeV5.h"

int main() {
    Time* t = Time::Parse("12:34:56");

    std::cout << t->toString() << "\n";

    delete t;

    return 0;
}