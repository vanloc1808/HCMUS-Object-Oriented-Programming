#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Line.h"

Line::Line() {
    this->_start = new Point(0, 0);
    this->_end = new Point(0, 0);

    Line::instanceCount++;
}

Line::Line(Point* st, Point* end) {
    this->_start = new Point(st->x(), st->y());
    this->_end = new Point(end->x(), end->y());

    Line::instanceCount++;
}

Line::Line(const Line& p) {
    this->_start = new Point(p._start->x(), p._start->y());
    this->_end = new Point(p._end->x(), p._end->y());

    Line::instanceCount++;
}

Line::~Line() {
    if (this->_start) {
        delete this->_start;
        this->_start = nullptr;
    }

    if (this->_end) {
        delete this->_end;
        this->_end = nullptr;
    }
}

float Line::length() {
    return Point::calcDistance(this->_start, this->_end);
}

std::string Line::toString() const {
    std::stringstream ss;
    ss << "Line: " << this->_start->toString() << " - " << this->_end->toString();
    return ss.str();
}

Line& Line::operator=(const Line& p) {
    if (this != &p) {
        this->_start = new Point(p._start->x(), p._start->y());
        this->_end = new Point(p._end->x(), p._end->y());
    }

    return *this;
}

std::istream& operator>>(std::istream& inDev, Line& l) {
    inDev >> *l._start >> *l._end;

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Line& l) {
    outDev << l.toString();

    return outDev;
}

Line* Line::Parse(std::string line) {
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
        return new Line(new Point(numbers[0], numbers[1]), new Point(numbers[2], numbers[3]));
    } else {
        return nullptr;
    }
}