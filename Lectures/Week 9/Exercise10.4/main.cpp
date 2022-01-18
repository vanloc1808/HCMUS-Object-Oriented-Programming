#include <iostream>
#include "Room.h"
#include "Hotel.h"

int main() {
    Hotel h;

    std::cout << "Input a hotel\n";
    std::cout << "First, input the number of rooms\n";
    std::cout << "For each room:\n";
    std::cout << "Enter 1 if that is room type A,\n";
    std::cout << "Enter 2 if that is room type B,\n";
    std::cout << "Enter 3 if that is room type C.\n";
    std::cout << "Followed by the number of days rented\n";

    h.input();

    std::cout << "Total cost is: " << h.totalIncome() << "\n";

    return 0;
}