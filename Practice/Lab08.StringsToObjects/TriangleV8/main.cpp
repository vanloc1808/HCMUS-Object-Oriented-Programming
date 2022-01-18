#include <iostream>
#include "Triangle.h"

int Point::instanceCount = 0;

int main() {
    Triangle* t = Triangle::Parse("(0, 0), (0, 4), (4, 0)");

    std::cout << t->toString() << "\n";

    std::cout << "Area: " << t->area() << "\n";

    std::cout << "Perimeter: " << t->perimeter() << "\n";

    delete t;
    
    return 0;
}