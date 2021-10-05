#include <iostream>
#include "Triangle.h"

//We will set the default value for all vertices as the coordinate center
Triangle::Triangle() {
    Point o(0, 0); 
    this->_a = o;
    this->_b = o;
    this->_c = o;
}

//In this section, we will assume that the three points satisfy the triangle inequality,
//which means that they form a triangle.
Triangle::Triangle(Point a, Point b, Point c) {
    this->_a = a;
    this->_b = b;
    this->_c = c;
}

Triangle::Triangle(const Triangle& t) {
    this->_a = t._a;
    this->_b = t._b;
    this->_c = t._c;
}

//Because the three vertices are equivalent, so it can be randomly set and gotten.
Point* Triangle::getVertices() {
    Point* res = new Point[3];
    res[0] = this->_a;
    res[1] = this->_b;
    res[2] = this->_c;
    return res;
}

void Triangle::setVertices(Point* v) {
    this->_a = v[0];
    this->_b = v[1];
    this->_c = v[2];
}