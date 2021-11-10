#ifndef _CIRCLE_H
#define _CIRCLE_H

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

    std::string toString();

    //don't need to overload the assignment operator
    //because we don't use pointer here ._.
};

#endif