#include "Random.h"

int Random::result = 0;

int main() {
    Random r1;

    std:: cout << r1.next() << "\n";
    std::cout << r1.next(4) << "\n";
}