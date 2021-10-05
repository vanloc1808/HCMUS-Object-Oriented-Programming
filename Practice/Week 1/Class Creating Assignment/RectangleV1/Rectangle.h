#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Point.h"

class Rectangle {
private:
    Point _topLeft;
    Point _bottomRight;

public:
    //defaul constructor
    Rectangle();

    //fully-parameterized constructor
    Rectangle(Point top, Point bottom);

    //copy constructor
    Rectangle(const Rectangle& r);

    //getter for topleft and bottomright
    Point getTopLeft();

    Point getBottomRight();

    //setter for topleft and bottomright

    void setTopLeft(Point newTL);

    void setBottomRight(Point newBR);
};

#endif