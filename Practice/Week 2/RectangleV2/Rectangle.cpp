#include <iostream>
#include <cmath>
#include "Rectangle.h"

Rectangle::Rectangle() {
    Point* a = new Point(1, 10);
    Point* b = new Point(10, 1);

    this->_topLeft = a;
    this->_bottomRight = b;
}

Rectangle::Rectangle(Point* top, Point* bottom) {
    this->_topLeft = top;
    this->_bottomRight = bottom;
}

Rectangle::Rectangle(const Rectangle& r) {
    this->_topLeft = r._topLeft;
    this->_bottomRight = r._bottomRight;
}

Rectangle::~Rectangle() {
        delete[] this->_topLeft;
        delete[] this->_bottomRight;
    }

Point* Rectangle::getTopLeft() {
    return this->_topLeft;
}

Point* Rectangle::getBottomRight() {
    return this->_bottomRight;
}

void Rectangle::setTopLeft(Point* newTL) {
    this->_topLeft = newTL;
}

void Rectangle::setBottomRight(Point* newBR) {
    this->_topLeft = newBR;
}

double Rectangle::perimeter() {
    double deltaX = fabs(this->_topLeft->getX() - this->_bottomRight->getX());
    double deltaY = fabs(this->_topLeft->getY() - this->_bottomRight->getY());

    return 2 * (deltaX + deltaY);
}

double Rectangle::area() {
    double deltaX = fabs(this->_topLeft->getX() - this->_bottomRight->getX());
    double deltaY = fabs(this->_topLeft->getY() - this->_bottomRight->getY());

    return deltaX * deltaY;
}

void Rectangle::ouput() {
    std::cout << "Top left: ";
    this->_topLeft->output();
    std::cout << "\n";
    std::cout << "Bottom right: ";
    this->_bottomRight->output();
    std::cout << "\n";
}