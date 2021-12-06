#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <iostream>
#include <string>
#include "Point.h"

class Circle {
private:
    Point _center;
    double _radius;

public:
    //default constructor
    Circle();

    //fully-parameterized constructor
    Circle(Point c, double r);

    //copy constructor
    Circle(const Circle& c);

    ~Circle();

    //getter for center
    Point getCenter();

    //getter for radius
    double getRadius();

    //setter for center
    void setCenter(Point c);

    //setter for radius
    void setRadius(double r);

    double area();

    double perimeter();

    std::string toString() const;

    //don't need to overload the assignment operator
    //because we don't use pointer here ._.

    friend std::istream& operator>>(std::istream& inDev, Circle& c);

    friend std::ostream& operator<<(std::ostream& outDev, const Circle& c);

    static Circle* Parse(std::string line);

    bool operator>(Circle& c) {
        return this->area() > c.area();
    }
};

#endif