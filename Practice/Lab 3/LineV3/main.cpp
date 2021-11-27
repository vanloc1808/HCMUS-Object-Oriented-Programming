#include <iostream>
#include "Point.h"
#include "Line.h"

int Point::instanceCount = 0;
int Line::instanceCount = 0;
int main() {
    Point* st = new Point(4, 5);
    Point* end = new Point(-1, 2);

    Line l(st, end);

    std::cout << "First point: (" << st->x() << ", " << st->y() << ")\n";
    std::cout << "Second point: (" << end->x() << ", " << end->y() << ")\n";
    std::cout << "Length: " << l.length() << "\n";
    std::cout << "Points created: " << Point::instanceCount << "\n";
    std::cout << "Lines created: " << Line::instanceCount << "\n";

    return 0;

}
