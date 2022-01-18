#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Circle.h"

const double PI = 3.14159;

Circle::Circle() {
    Point o(0, 0); // the default center is the coordinate center
    double r = 0;

    this->_center = o;
    this->_radius = r;
}

Circle::Circle(Point c, double r) {
    this->_center = c;
    this->_radius = r;
}

Circle::Circle(const Circle& c) {
    this->_center = c._center;
    this->_radius = c._radius;
}

Circle::~Circle() {

}

Point Circle::getCenter() {
    Point res = this->_center;

    return res;
}

double Circle::getRadius() {
    double res = this->_radius;

    return res;
}

void Circle::setCenter(Point c) {
    this->_center = c;
}

void Circle::setRadius(double r) {
    if (r < 0) {
        r = 0; //ensure that the radius is nonnegative
    }

    this->_radius = r;
}

double Circle::area() {
    double res = PI * this->_radius * this->_radius;

    return res;
}

double Circle::perimeter() {
    double res = 2 * PI * this->_radius;

    return res;
}

std::string Circle::toString() const {
    std::stringstream ss;
    ss << "Circle[center = " << this->_center.toString() << ", radius = " << this->_radius << "]";

    return ss.str();
}

std::istream& operator>>(std::istream& inDev, Circle& c) {
    inDev >> c._center >> c._radius;

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Circle& c) {
    outDev << c.toString();

    return outDev;
}

Circle* Circle::Parse(std::string line) {
    std::string delim1 = ", ";
    std::string delim2 = "), ";

    int startPos = 0;

    if (line[startPos] == '(') {
        startPos++;
    }

    size_t foundPos = line.find(delim1, startPos);

    int i = 0;

    std::vector<float> numbers;

    while (foundPos != std::string::npos) {
        i++;

        int cnt = foundPos - startPos;

        std::string token = line.substr(startPos, cnt);

        numbers.push_back(std::stof(token));


        startPos = foundPos + delim1.length();

        foundPos = line.find(delim2, startPos);
    }

    int cnt = line.length() - startPos;

    std::string token = line.substr(startPos, cnt);

    numbers.push_back(std::stof(token));

    if (numbers.size() != 3) {
        return nullptr;
    }

    Point center(numbers[0], numbers[1]);

    double radius = numbers[2];

    Circle* c = new Circle(center, radius);

    return c;
}