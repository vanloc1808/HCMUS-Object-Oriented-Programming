#include <iostream>
#include "Triangle.h"

int main() {
    Triangle t1; //default
    t1.output();

    Point* a = new Point(0, 0);
    Point* b = new Point(1,1);
    Point* c = new Point(3, 0);
    Triangle t2(a, b, c);
    t2.output();

    Triangle t3(t2);
    t3.output();
}