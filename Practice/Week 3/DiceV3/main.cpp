#include "Dice.h"

int main() {
    Dice d;
    d.roll();
    d.roll();
    d.roll();
    d.roll();
    std::cout << "The number of rolls: " << d._rollCount << "\n";
}