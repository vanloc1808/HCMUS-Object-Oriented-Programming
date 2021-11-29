#include <iostream>
#include "Circle.h"

int Point::instanceCount = 0;

int main() {
    Circle* c = Circle::Parse("(1, 2), 1.8");

    std::cout << c->toString() << "\n";

    std::cout << "Area: " << c->area() << "\n";

    std::cout << "Perimeter: " << c->perimeter() << "\n";

    delete c;

    return 0;
}