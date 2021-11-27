#include <iostream>
#include <cmath>
#include "Rectangle.h"

Rectangle::Rectangle() {
    this->_topLeft = new Point(1, 10);
    this->_bottomRight = new Point(10, 1);

    Rectangle::instanceCount++;
}

Rectangle::Rectangle(Point* top, Point* bottom) {
    this->_topLeft = new Point(top->x(), top->y());
    this->_bottomRight = new Point(bottom->x(), bottom->y());

    Rectangle::instanceCount++;
}

Rectangle::Rectangle(const Rectangle& r) {
    this->_topLeft = new Point(r._topLeft->x(), r._topLeft->y());
    this->_bottomRight = new Point(r._bottomRight->x(), r._bottomRight->y());

    Rectangle::instanceCount++;
}

Rectangle::~Rectangle() {
    if (this->_topLeft) {
        delete this->_topLeft;
        this->_topLeft = nullptr;
    }

    if (this->_bottomRight) {
        delete this->_bottomRight;
        this->_bottomRight = nullptr;
    }
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
    double deltaX = fabs(this->_topLeft->x() - this->_bottomRight->x());
    double deltaY = fabs(this->_topLeft->y() - this->_bottomRight->y());

    return 2 * (deltaX + deltaY);
}

double Rectangle::area() {
    double deltaX = fabs(this->_topLeft->x() - this->_bottomRight->x());
    double deltaY = fabs(this->_topLeft->y() - this->_bottomRight->y());

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