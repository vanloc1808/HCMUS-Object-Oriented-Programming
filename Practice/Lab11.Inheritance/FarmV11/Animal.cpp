#include <iostream>
#include <cstdlib>
#include "Animal.h"

int Animal::bear() {
    return 0;
}

int Animal::giveMilk() {
    return 0;
}

void Animal::speak() {
    std::cout << "Animal\n";
}

int Cow::bear() {
    return rand() % 20 + 1;
}

int Cow::giveMilk() {
    return rand() % 21;
}

void Cow::speak() {
    std::cout << "Cow\n";
}

int Sheep::bear() {
    return rand() % 20 + 1;
}

int Sheep::giveMilk() {
    return rand() % 6;
}

void Sheep::speak() {
    std::cout << "Sheep\n";
}

int Goat::bear() {
    return rand() % 20 + 1;
}

int Goat::giveMilk() {
    return rand() % 11;
}

void Goat::speak() {
    std::cout << "Goat\n";
}