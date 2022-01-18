#ifndef _TRUCK_H
#define _TRUCK_H

#include <iostream>
#include "Motorbike.h"

const double FUEL_PER_100KM_TRUCK = 20;
const double BONUS_PER_10KG_TRUCK = 0.01;

class Truck : public Motorbike {
public:
    Truck() : Motorbike() { }

    Truck(const double f, const double p) : Motorbike(f, p) { }

    //run distance km
//check if the fuel is enough
bool run(double distance) {
    int fuel = this->getFuelRest();
    int weight = this->getProductWeight();
    double fuelNeed = (distance / 100) * FUEL_PER_100KM_TRUCK + (distance / 100) * (weight / 10) * BONUS_PER_10KG_TRUCK;

    if (fuelNeed > fuel) {
        std::cout << "Cannot run! Not enough fuel!\n";

        return false;
    } 

    std::cout << "Run " << distance << " kilometers.\n";

    this->reduceFuel(fuelNeed);

    return true;
}

};

#endif