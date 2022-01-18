#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main() {
    Cow c1, c2, c3;
    Sheep s1, s2, s3, s4;
    Goat g1, g2, g3, g4, g5;

    Farm f;
    f.addCow(c1);
    f.addCow(c2);
    f.addCow(c3);
    f.addSheep(s1);
    f.addSheep(s2);
    f.addSheep(s3);
    f.addSheep(s4);
    f.addGoat(g1);
    f.addGoat(g2);
    f.addGoat(g3);
    f.addGoat(g4);
    f.addGoat(g5);

    f.allSpeak();
    std::cout << "Milk: " << f.allMilk() << "\n";
    std::cout << "Babies: " << f.allBabies() << "\n";

    return 0;

}