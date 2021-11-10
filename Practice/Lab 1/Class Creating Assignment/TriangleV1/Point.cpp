#include <iostream>
#include "Point.h"

Point::Point() {
    this->_x = 0;
    this->_y = 0;
}

Point::Point(double x, double y) {
    this->_x = x;
    this->_y = y;
}

Point::Point(const Point& p) {
    this->_x = p._x;
    this->_y = p._y;
}

void Point::output() {
    std::cout << "(" << this->_x << ", " << this->_y << ")";
}