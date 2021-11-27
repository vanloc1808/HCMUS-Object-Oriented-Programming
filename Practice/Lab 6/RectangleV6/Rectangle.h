#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Point.h"

class Rectangle {
private:
    Point* _topLeft;
    Point* _bottomRight;

public:
    static int instanceCount;

public:
    //defaul constructor
    Rectangle();

    //fully-parameterized constructor
    Rectangle(Point* top, Point* bottom);

    //copy constructor
    Rectangle(const Rectangle& r);

    //getter for topleft and bottomright
    Point* getTopLeft();

    Point* getBottomRight();

    //destructor
    ~Rectangle();

    //setter for topleft and bottomright

    void setTopLeft(Point* newTL);

    void setBottomRight(Point* newBR);

    double perimeter();

    double area();

    std::string toString() const;

    Rectangle& operator=(const Rectangle& r);

    friend std::istream& operator>>(std::istream& inDev, Rectangle& r);

    friend std::ostream& operator<<(std::ostream& outDev, const Rectangle& r);
};

#endif