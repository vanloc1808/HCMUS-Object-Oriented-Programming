#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main() {
    Farm f;

    f.addAnimal(new Cow());
    f.addAnimal(new Sheep());
    f.addAnimal(new Sheep());
    f.addAnimal(new Goat());
    f.addAnimal(new Goat());
    f.addAnimal(new Goat());
    f.addAnimal(new Cow());
    f.addAnimal(new Goat());
    f.addAnimal(new Sheep());

    std::cout << "Before giving birth:\n";
    f.allSpeak();
    std::cout << "Number of babies: " << f.allGiveBirth() << "\n";
    std::cout << "Number of milk: " << f.allGiveMilk() << "\n";
    std::cout << "After giving birth\n";
    f.allSpeak();

    return 0;
}