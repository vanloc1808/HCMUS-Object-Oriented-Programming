#include <iostream>
#include <climits>
#include "Fraction.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "DynamicArray.h"

int Point::instanceCount = 0;
int Line::instanceCount = 0;
int Rectangle::instanceCount = 0;

int main() {
    
    DynamicArray<int> ai;
    ai.pushBack(3);
    ai.pushBack(5);
    ai.pushBack(1);
    ai.sort();
    std::cout << "Int\n";
    std::cout << ai.toString() << "\n";

    DynamicArray<float> af;
    af.pushBack(3.5);
    af.pushBack(5.5);
    af.pushBack(1.5);
    af.sort();
    std::cout << "Float\n";
    std::cout << af.toString() << "\n";

    DynamicArray<Fraction> afr;
    afr.pushBack(Fraction(3, 5));
    afr.pushBack(Fraction(5, 5));
    afr.pushBack(Fraction(1, 5));
    afr.sort();
    std::cout << "Fraction\n";
    std::cout << afr.toString() << "\n";

    DynamicArray<Point> ap;
    ap.pushBack(Point(3, 5));
    ap.pushBack(Point(5, 5));
    ap.pushBack(Point(1, 5));
    ap.sort();
    std::cout << "Point\n";
    std::cout << ap.toString() << "\n";

    DynamicArray<Line> al;
    al.pushBack(Line(new Point(3, 5), new Point(5, 5)));
    al.pushBack(Line(new Point(7, 5), new Point(5, 5)));
    al.pushBack(Line(new Point(1, 5), new Point(5, 5)));
    al.sort();
    std::cout << "Line\n";
    std::cout << al.toString() << "\n";

    DynamicArray<Triangle> at;
    at.pushBack(Triangle(new Point(1, 3), new Point(5, 5), new Point(1, 5)));
    at.pushBack(Triangle(new Point(1, 4), new Point(5, 5), new Point(1, 5)));
    at.pushBack(Triangle(new Point(1, 2), new Point(5, 5), new Point(1, 5)));
    at.sort();
    std::cout << "Triangle\n";
    std::cout << at.toString() << "\n";

    DynamicArray<Circle> ac;
    ac.pushBack(Circle(Point(1, 3), 5));
    ac.pushBack(Circle(Point(1, 4), 6));
    ac.pushBack(Circle(Point(1, 2), 7));
    ac.sort();
    std::cout << "Circle\n";
    std::cout << ac.toString() << "\n";

    DynamicArray<Rectangle> ar;
    ar.pushBack(Rectangle(new Point(1, 5), new Point(5, 3)));
    ar.pushBack(Rectangle(new Point(1, 5), new Point(5, 4)));
    ar.pushBack(Rectangle(new Point(1, 5), new Point(5, 2)));
    ar.sort();
    std::cout << "Rectangle\n";
    std::cout << ar.toString() << "\n";

    return 0;
}