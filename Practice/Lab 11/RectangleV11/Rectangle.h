#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>
#include <cmath>

class Rectangle {
private:
    float _width;

    float _height;

public:
    Rectangle() {
        this->_width = 0;
        this->_height = 0;
    }

    Rectangle(float w, float h) {
          w = fabs(w);
          h = fabs(h);

          this->_width = w;
          this->_height = h;      
    }

    float area() {
        return this->_width * this->_height;
    }

    float perimeter() {
        return 2 * (this->_width + this->_height);
    }

    void name() {
        std::cout << "Rectangle\n";
    }
};

class Square : public Rectangle {
public:
    Square() : Rectangle() {

    }

    Square(float a) : Rectangle(a, a) {

    };

    void name() {
        std::cout << "Square\n";
    }

};

#endif // _RECTANGLE_H_