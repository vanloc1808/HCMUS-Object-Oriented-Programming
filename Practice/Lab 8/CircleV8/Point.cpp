#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "Point.h"

Point::Point() {
    this->_x = 0;
    this->_y = 0;

    Point::instanceCount++;
}

Point::Point(const float x, const float y) {
    this->_x = x;
    this->_y = y;

    Point::instanceCount++;
}

Point::~Point() {
    
}

float Point::calcDistanceTo(const Point* other) const {
    float dx = this->_x - other->_x;
    float dy = this->_y - other->_y;

    return sqrt(dx * dx + dy * dy);
}

float Point::calcDistance(const Point* a, const Point* b) {
    return a->calcDistanceTo(b);
}

std::string Point::toString() const {
    std::stringstream ss;

    ss << "(" << this->_x << ", " << this->_y << ")";

    return ss.str();
}

std::istream& operator>>(std::istream& inDev, Point& p) {
    inDev >> p._x >> p._y;

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Point& p) {
    outDev << p.toString();

    return outDev;
}