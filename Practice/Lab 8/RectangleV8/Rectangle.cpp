#include <iostream>
#include <cmath>
#include <string>
#include <vector>
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

std::string Rectangle::toString() const {
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

std::istream& operator>>(std::istream& inDev, Rectangle& r) {
    inDev >> *r._topLeft >> *r._bottomRight;

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Rectangle& r) {
    outDev << r.toString();

    return outDev;
}

Rectangle* Rectangle::Parse(std::string line) {
    std::string delimiter = ", ";
    std::string bracket = "), (";
    std::string end = ")";

    int startPos = 0;

    if (line[startPos] == '(') {
        startPos++;
    }

    size_t foundPos = line.find(delimiter, startPos);

    int i = 0;

    std::vector<float> numbers;

    while (foundPos != std::string::npos) {
        i++;
        int cnt = foundPos - startPos;

        std::string token = line.substr(startPos, cnt);

        numbers.push_back(std::stof(token));

        if (i == 1) {
            startPos = foundPos + delimiter.length();
            foundPos = line.find(bracket, startPos);
        } else if (i == 2) {
            startPos = foundPos + bracket.length();
            foundPos = line.find(delimiter, startPos);
        } else if (i == 3) {
            startPos = foundPos + delimiter.length();
            foundPos = line.find(end, startPos);
        } else {
            break;
        }
    }

    if (numbers.size() == 4) {
        return new Rectangle(new Point(numbers[0], numbers[1]), new Point(numbers[2], numbers[3]));
    } else {
        return nullptr;
    }
}