#include <iostream>
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