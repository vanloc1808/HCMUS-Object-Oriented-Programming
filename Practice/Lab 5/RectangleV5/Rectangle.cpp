#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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

std::string Rectangle::toString() {
    std::stringstream ss;
    ss << "Top left: ";
    ss << this->_topLeft->toString();
    ss << " and ";
    ss << "Bottom right: ";
    ss << this->_bottomRight->toString();
    return ss.str();
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    this->_topLeft = new Point(r._topLeft->x(), r._topLeft->y());
    this->_bottomRight = new Point(r._bottomRight->x(), r._bottomRight->y());

    return *this;
}