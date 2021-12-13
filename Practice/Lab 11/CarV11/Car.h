#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>

class Car {
public:
    Car() {

    }

    ~Car() {

    }

    void startEngine() {
        std::cout << "Starting engine\n";
    }
};

class Carbriolet : public Car {
public:
    Carbriolet() : Car() {

    }

    ~Carbriolet() {
        
    }

    void startEngine() {
        std::cout << "Removing roof\n";
        Car::startEngine();
    }
};

#endif // _CAR_H_