#include <iostream>
#include "Animal.h"

int main() {
    Animal* a = new Panther();
    Animal* b = new Dog();
    Animal* c = new Horse();

    compareSpeed(a, b);
    compareSpeed(b, c);

    return 0;
}