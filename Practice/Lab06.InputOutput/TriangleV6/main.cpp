#include <iostream>
#include "Triangle.h"

int Point::instanceCount = 0;

int main() {
    Triangle t1; //default
    std::cout << "t1: " << t1.toString() << "\n";
    std::cout << "t1 area: " << t1.area() << "\n";
    std::cout << "t1 perimeter: " << t1.perimeter() << "\n";

    Point* a = new Point(0, 0);
    Point* b = new Point(1,1);
    Point* c = new Point(3, 0);
    Triangle t2(a, b, c);
    std::cout << "t2: " << t2.toString() << "\n";
    std::cout << "t2 area: " << t2.area() << "\n";
    std::cout << "t2 perimeter: " << t2.perimeter() << "\n";

    Triangle t3(t2);
    std::cout << "t3: " << t3.toString() << "\n";
    std::cout << t3 << "\n";
    std::cout << "t3 area: " << t3.area() << "\n";
    std::cout << "t3 perimeter: " << t3.perimeter() << "\n";
    
    return 0;
}