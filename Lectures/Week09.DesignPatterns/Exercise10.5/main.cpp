#include <iostream>
#include "Land.h"
#include "Company.h"

int main() {
    Company c;
    
    std::cout << "Input a company\n";
    std::cout << "First, input the number of lands\n";
    std::cout << "For each land, enter the number 0 if that is rectangle, enter another number if that is trapezium\n";
    std::cout << "For rectangle, enter: ID, price unit per m^2, length, and width\n";
    std::cout << "For trapezium, enter: ID, price unit per m^2, small base, big base, and height\n";

    c.input();

    std::cout << "Total area: " << c.totalArea() << "\n";
    std::cout << "Total price: " << c.totalPrice() << "\n";

    return 0;
}