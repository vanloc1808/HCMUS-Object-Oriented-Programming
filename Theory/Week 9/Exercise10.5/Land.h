#ifndef _LAND_H_
#define _LAND_H_

#include <iostream>
#include <string>

class Land {
private:
    std::string id;
    float priceUnit;

protected:
    float discount;

public:
    virtual float area() = 0;

    virtual void input() {
        std::cin.ignore();
        std::cin >> this->id;
        std::cin >> this->priceUnit;
    }

    float price() {
        return this->area() * this->priceUnit * (1 - this->discount);
    }
};

class RectangleLand : public Land {
private:
    float length;
    float width;

public:
    RectangleLand() : Land() {
        this->discount = 0;
    }

    void input() {
        Land::input();
        std::cin >> this->length;
        std::cin >> this->width;
    }

    float area() {
        return this->length * this->width;
    }
};

class TrapeziumLand : public Land {
private:
    float smallBase;
    float bigBase;
    float height;  

public:
    TrapeziumLand() : Land() {
        this->discount = 0.05;
    }

    void input() {
        Land::input();
        std::cin >> this->smallBase;
        std::cin >> this->bigBase;
        std::cin >> this->height;
    }

    float area() {
        return (this->smallBase + this->bigBase) / 2 * this->height;
    }
};

#endif // _LAND_H_