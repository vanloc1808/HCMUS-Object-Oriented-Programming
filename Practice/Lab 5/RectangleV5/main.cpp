#include <iostream>
#include "Rectangle.h"

int Point::instanceCount = 0;
int Rectangle::instanceCount = 0;

int main() {
    
    Rectangle ra; //default constructor
    std::cout << ra.toString() << "\n";

    Point* a = new Point(-1, 10);
    Point* b = new Point(9, 1);

    Rectangle rb(a, b);
    std::cout << rb.toString() << "\n";
    std::cout << rb.perimeter() << " " << rb.area() << "\n";

    Rectangle rc(a, b);
    std::cout << rc.toString() << "\n";
    std::cout << rc.perimeter() << " " << rc.area() << "\n";

    std::cout << "Points created: " << Point::instanceCount << "\n";
    std::cout << "Rectangles created: " << Rectangle::instanceCount << "\n";

    return 0;
}