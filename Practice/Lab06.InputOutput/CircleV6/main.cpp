#include <iostream>
#include "Circle.h"

int Point::instanceCount = 0;

int main() {
    Point p(1, 2);
    double r = 4;

    Circle c(p, r);

    std::cout << c.toString() << "\n";
    std::cout << c << "\n";
    std::cout << "Area: " << c.area() << "\n";
    std::cout << "Perimeter: " << c.perimeter() << "\n";

    return 0;
}