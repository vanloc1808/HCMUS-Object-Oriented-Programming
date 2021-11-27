#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point* _a;
    Point* _b;
    Point* _c;

public:
    //default constructor
    Triangle();

    //fully-parameterized constructor
    Triangle(Point* a, Point* b, Point* c);

    //copy constructor
    Triangle(const Triangle& t);

    //destructor
    ~Triangle();
    
    //because three vertices of a triangle is equivalent,
    //we need to return an array of 3 elements, consisting of 3 vertices
    Point** getVertices();

    //set new three vertices for the triangle
    void setVertices(Point** v);

    double perimeter();

    double area();

    std::string toString() const;

    Triangle& operator=(const Triangle& t);

    friend std::istream& operator>>(std::istream& inDev, Triangle& t);

    friend std::ostream& operator<<(std::ostream& outDev, const Triangle& t);
};

#endif