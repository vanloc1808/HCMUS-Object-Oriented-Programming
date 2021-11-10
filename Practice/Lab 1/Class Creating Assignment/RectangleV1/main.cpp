#include <iostream>
#include "Rectangle.h"

int main() {
    Point a(1, 2);
    Point b(4, 5);

    Rectangle r(a, b);

    Point topLeft = r.getTopLeft();
    Point bottomRight = r.getBottomRight();

    std::cout << "The top left point is: "; 
    topLeft.output(); 
    std::cout << "\n";
    std::cout << "The bottom right point is: ";
    bottomRight.output();
    std::cout << "\n";

    return 0;
}