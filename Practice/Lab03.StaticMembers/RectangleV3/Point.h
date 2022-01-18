#ifndef _POINT_H
#define _POINT_H

class Point {
public:
    static int instanceCount;

private:
    float _x;
    float _y;

public:
    const float x() {return _x;};

    const float y() {return _y;};

    void setX(const float value) {_x = value;};

    void setY(const float value) {_y = value;};

public:
    Point();

    Point(const float, const float);

    ~Point();

    void output();

public:
    float calcDistanceTo(const Point* other) const;

public:
    static float calcDistance(const Point* a, const Point* b);

};

#endif