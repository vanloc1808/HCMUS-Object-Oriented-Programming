#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Figure.h"

Figure::Figure() {

}

Figure::~Figure() {

}

Line::Line() {
    srand(time(NULL));

    this->_length = rand() % 100 + 1;
}

Line::~Line() {

}

void Line::draw() {
    std::cout << "Line\n";
}

Rectangle::Rectangle() {
    srand(time(NULL));

    this->_width = rand() % 100 + 1;
    this->_height = rand() % 100 + 1;
}

Rectangle::~Rectangle() {

}

void Rectangle::draw() {
    std::cout << "Rectangle\n";
}

Ellipse::Ellipse() {
    srand(time(NULL));

    this->_longAxis = rand() % 100 + 1;
    this->_shortAxis = rand() % 100 + 1;

    if (this->_longAxis < this->_shortAxis) {
        std::swap(this->_longAxis, this->_shortAxis);
    }
}

Ellipse::~Ellipse() {

}

void Ellipse::draw() {
    std::cout << "Ellipse\n";
}