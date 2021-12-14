#include <iostream>
#include "Ellipse.h"

int main() {
    Ellipse e(5, 2);
    e.name();
    std::cout << "Area: " << e.area() << "\n";
    std::cout << "Perimeter: " << e.perimeter() << "\n";

    Circle c(10);
    c.name();
    std::cout << "Area: " << c.area() << "\n";
    std::cout << "Perimeter: " << c.perimeter() << "\n";

    return 0;
}