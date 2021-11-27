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

    std::string toString() const;

    Line& operator=(const Line& p);

    friend std::istream& operator>>(std::istream& inDev, Line& l);

    friend std::ostream& operator<<(std::ostream& outDev, const Line& l);
};

#endif