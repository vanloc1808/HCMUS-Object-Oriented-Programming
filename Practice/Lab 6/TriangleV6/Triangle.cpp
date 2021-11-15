#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
    this->_a = new Point(a->x(), a->y());
    this->_b = new Point(b->x(), b->y());
    this->_c = new Point(c->x(), c->y());
}

Triangle::Triangle(const Triangle& t) {
    this->_a = new Point(t._a->x(), t._a->y());
    this->_b = new Point(t._b->x(), t._b->y());
    this->_c = new Point(t._c->x(), t._c->y());
}

Triangle::~Triangle() {
        if (this->_a) {
            delete this->_a;
            this->_a = nullptr;
        }

        if (this->_b) {
            delete this->_b;
            this->_b = nullptr;
        }

        if (this->_c) {
            delete this->_c;
            this->_c = nullptr;
        }
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
    double ab = this->_a->calcDistanceTo(this->_b);
    double ac = this->_a->calcDistanceTo(this->_c);
    double bc = this->_b->calcDistanceTo(this->_c);

    return ab + bc + ac;
}

double Triangle::area() {
    double ab = this->_a->calcDistanceTo(this->_b);
    double ac = this->_a->calcDistanceTo(this->_c);
    double bc = this->_b->calcDistanceTo(this->_c);

    double p = (ab + ac + bc) / 2;
    
    return sqrt(p * (p - ab) * (p - bc) * (p - ac));
}

std::string Triangle::toString() const{
    std::stringstream ss;
    ss << "Triangle: " << this->_a->toString() << " " << this->_b->toString() << " " << this->_c->toString();
    return ss.str();
}

Triangle& Triangle::operator=(const Triangle& t) {
    this->_a = new Point(t._a->x(), t._a->y());
    this->_b = new Point(t._b->x(), t._b->y());
    this->_c = new Point(t._c->x(), t._c->y());
    
    return *this;
}

std::istream& operator>>(std::istream& inDev, Triangle& t) {
    inDev >> *(t._a) >> *(t._b) >> *(t._c);

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Triangle& t) {
    outDev << t.toString();

    return outDev;
}