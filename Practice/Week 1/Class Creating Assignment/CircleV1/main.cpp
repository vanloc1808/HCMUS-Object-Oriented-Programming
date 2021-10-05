#include <iostream>
#include "Circle.h"

int main() {
    Point p(1, 2);
    double r = 4;

    Circle c(p, r);

    //test the getter
    Point center = c.getCenter();
    double radius = c.getRadius();
    std::cout << "Old: Center: ";
    center.output();
    std::cout << ", radius: " << radius << "\n";

    //test the setter
    Point newp(2, 3);
    double newr = 5;
    c.setCenter(newp);
    c.setRadius(newr);
    center = c.getCenter();
    radius = c.getRadius();
    std::cout << "New: Center: ";
    center.output();
    std::cout << ", radius: " << radius << "\n";

    return 0;
}