#ifndef _ELLIPSE_H
#define _ELLIPSE_H

#include <iostream>
#include <cmath>

float const PI = 3.14159;

class Ellipse {
private:
    float _longAxis;
    float _shortAxis;

public:
    Ellipse() {
        this->_longAxis = 0;
        this->_shortAxis = 0;
    }

    Ellipse(float l, float s) {
        l = fabs(l);
        s = fabs(s);

        if (l < s) {
            std::swap(l, s);
        }

        this->_longAxis = l;
        this->_shortAxis = s;
    }

    float perimeter() {
        return 2 * PI * sqrt((this->_longAxis * this->_longAxis + this->_shortAxis * this->_shortAxis) / 2);
    }

    float area() {
        return PI * this->_longAxis * this->_shortAxis;
    }

    void name() {
        std::cout << "Ellipse\n";
    }
};

class Circle : public Ellipse {
public:
    Circle() : Ellipse() {

    }

    Circle(float r) : Ellipse(r, r) {

    }

    void name() {
        std::cout << "Circle\n";
    }
};

#endif // _ELLIPSE_H