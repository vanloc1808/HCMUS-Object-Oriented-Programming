#ifndef _FIGURE_H_
#define _FIGURE_H_

class Figure {
private:

public:
    Figure();

    ~Figure();

    virtual void draw() = 0;
};

class Line : public Figure {
private:
    float _length;

public:
    Line();

    ~Line();

    void draw();
};

class Rectangle : public Figure {
private:
    float _width;

    float _height;

public:
    Rectangle();

    ~Rectangle();

    void draw();
};

class Ellipse : public Figure {
private:
    float _longAxis;
    
    float _shortAxis;

public:
    Ellipse();

    ~Ellipse();

    void draw();
};

#endif // _FIGURE_H_