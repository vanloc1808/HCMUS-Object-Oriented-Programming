#ifndef _LINE_H
#define _LINE_H

#include "Point.h"

class Line {
private:
    Point* _start;
    Point* _end;

public: 
    static int instanceCount;

public:
    Line();
    Line(Point* st, Point* end);
    Line(const Line& p);
    ~Line();

    float length();

    std::string toString();

    Line& operator=(const Line& p);
};

#endif