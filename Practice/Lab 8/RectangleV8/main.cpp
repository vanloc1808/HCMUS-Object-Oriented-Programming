#include <iostream>
#include "Rectangle.h"

int Point::instanceCount = 0;
int Rectangle::instanceCount = 0;

int main() {
    Rectangle* r = Rectangle::Parse("(1, 20), (6, 15)");
    if (!r) {
        std::cout << "Error parsing rectangle" << "\n";
    } else {
        std::cout << r->toString() << "\n";
        std::cout << "Area: " << r->area() << "\n";
        std::cout << "Perimeter: " << r->perimeter() << "\n";
        
        delete r;
    }

    return 0;
}