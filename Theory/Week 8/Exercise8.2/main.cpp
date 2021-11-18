#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

int Rectangle::instanceCount = 0;
int Point::instanceCount = 0;


int main() {
    Figure** f = new Figure*[3];
    Point* a = new Point(1, 4);
    Point* b = new Point(3, 2);
    Point* c = new Point(1, 2);

    f[0] = new Rectangle(a, b);
    f[1] = new Triangle(a, b, c);
    f[2] = new Circle(*b, 4);

    for (int i = 0; i < 3; i++) {
        f[i]->showInfo();
    }

    for (int i = 0; i < 3; i++) {
        delete[] f[i];
    }

    delete[] f;

    return 0;
}