#include <iostream>
#include <cstdlib>
#include "Animal.h"

Cow::~Cow() {

}

int Cow::giveMilk() {
    srand(time(NULL));
    return (rand() % 20) + 1;
}

int Cow::giveBirth() {
    srand(time(NULL));

    return rand() % 21;
}

void Cow::speak() {
    std::cout << "Cow\n";
}

Sheep::~Sheep() {

}

int Sheep::giveMilk() {
    srand(time(NULL));

    return (rand() % 20) + 1;
}

int Sheep::giveBirth() {
    srand(time(NULL));

    return rand() % 6;
}

void Sheep::speak() {
    std::cout << "Sheep\n";
}

Goat::~Goat() {

}

int Goat::giveMilk() {
    srand(time(NULL));

    return (rand() % 20) + 1;
}

int Goat::giveBirth() {
    srand(time(NULL));
    
    return rand() % 11;
}

void Goat::speak() {
    std::cout << "Goat\n";
}