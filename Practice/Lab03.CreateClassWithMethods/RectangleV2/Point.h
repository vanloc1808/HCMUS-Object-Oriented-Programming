#ifndef _POINT_H
#define _POINT_H

class Point {
private:
    double _x;
    double _y;

public:
    //default constructor
    Point();

    //fully-parameterized constructor
    Point(double x, double y);

    //copy constructor
    Point(const Point& p);

    double getX();
    
    double getY();

    void output();
};

#endif