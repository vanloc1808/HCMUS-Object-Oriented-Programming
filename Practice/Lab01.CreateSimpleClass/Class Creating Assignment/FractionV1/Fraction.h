#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
private:
    int _num;
    int _den;

public: 
    //default constructor
    Fraction();

    //fully-parameterized constructor
    Fraction(int n, int d);

    //partly-parameterized constructor, create a fraction with the same value of an integer
    Fraction(int x);

    //copy constructor
    Fraction(const Fraction& fr);

    //getter for numerator and denominator
    int getNum();

    int getDen();

    //setter for numerator and denominator

    void setNum(int n);

    void setDen(int d);

    void output();
};

#endif