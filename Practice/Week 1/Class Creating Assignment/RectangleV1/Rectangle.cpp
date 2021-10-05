#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() {
    Point o(0, 0); // default initialized with topLeft = bottomRight = the coordinate center

    this->_topLeft = o;
    this->_bottomRight = o;
}

Rectangle::Rectangle(Point top, Point bottom) {
    this->_topLeft = top;
    this->_bottomRight = bottom;
}

Rectangle::Rectangle(const Rectangle& r) {
    this->_topLeft = r._topLeft;
    this->_bottomRight = r._bottomRight;
}

Point Rectangle::getTopLeft() {
    return this->_topLeft;
}

Point Rectangle::getBottomRight() {
    return this->_bottomRight;
}

void Rectangle::setTopLeft(Point newTL) {
    this->_topLeft = newTL;
}

void Rectangle::setBottomRight(Point newBR) {
    this->_topLeft = newBR;
}