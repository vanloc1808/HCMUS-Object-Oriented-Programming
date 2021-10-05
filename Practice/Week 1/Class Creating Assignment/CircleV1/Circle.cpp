#include <iostream>
#include "Circle.h"

Circle::Circle() {
    Point o(0, 0); // the default center is the coordinate center
    double r = 0;

    this->_center = o;
    this->_radius = r;
}

Circle::Circle(Point c, double r) {
    this->_center = c;
    this->_radius = r;
}

Circle::Circle(const Circle& c) {
    this->_center = c._center;
    this->_radius = c._radius;
}

Point Circle::getCenter() {
    Point res = this->_center;

    return res;
}

double Circle::getRadius() {
    double res = this->_radius;

    return res;
}

void Circle::setCenter(Point c) {
    this->_center = c;
}

void Circle::setRadius(double r) {
    if (r < 0) {
        r = 0; //ensure that the radius is nonnegative
    }

    this->_radius = r;
}