#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle r(1, 2);
    r.name();
    std::cout << "Area: " << r.area() << "\n";
    std::cout << "Perimeter: " << r.perimeter() << "\n";

    Square s(4);
    s.name();
    std::cout << "Area: " << s.area() << "\n";
    std::cout << "Perimeter: " << s.perimeter() << "\n";

    return 0;
}