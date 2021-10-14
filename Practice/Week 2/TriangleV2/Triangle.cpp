#include <iostream>
#include <cmath>
#include "Triangle.h"

//We will set the default value for all vertices as the coordinate center
Triangle::Triangle() {
    Point* a = new Point(1, 1);
    Point* b = new Point(1, 2);
    Point* c = new Point(4, 2);

    this->_a = a;
    this->_b = b;
    this->_c = c;
}

//In this section, we will assume that the three points satisfy the triangle inequality,
//which means that they form a triangle.
Triangle::Triangle(Point* a, Point* b, Point* c) {
    this->_a = a;
    this->_b = b;
    this->_c = c;
}

Triangle::Triangle(const Triangle& t) {
    this->_a = t._a;
    this->_b = t._b;
    this->_c = t._c;
}

Triangle::~Triangle() {
        delete[] this->_a;
        delete[] this->_b;
        delete[] this->_c;
    }

//Because the three vertices are equivalent, so it can be randomly set and gotten.
Point** Triangle::getVertices() {
    Point** res = new Point*[3];
    res[0] = this->_a;
    res[1] = this->_b;
    res[2] = this->_c;
    return res;
}

void Triangle::setVertices(Point** v) {
    this->_a = v[0];
    this->_b = v[1];
    this->_c = v[2];
}

double Triangle::perimeter() {
    double ab = this->_a->distance(this->_b);
    double ac = this->_a->distance(this->_c);
    double bc = this->_b->distance(this->_c);

    return ab + bc + ac;
}

double Triangle::area() {
    double ab = this->_a->distance(this->_b);
    double ac = this->_a->distance(this->_c);
    double bc = this->_b->distance(this->_c);

    double p = (ab + ac + bc) / 2;
    
    return sqrt(p * (p - ab) * (p - bc) * (p - ac));
}

void Triangle::output() {
    std::cout << "First vertex: ";
    this->_a->output();
    std::cout << "\n";

    std::cout << "Second vertex: ";
    this->_b->output();
    std::cout << "\n";

    std::cout << "Third vertex: ";
    this->_c->output();
    std::cout << "\n";

    std::cout << "Perimeter: " << this->perimeter() << "\n";
    std::cout << "Area: " << this->area() << "\n";
    std::cout << "\n";
}