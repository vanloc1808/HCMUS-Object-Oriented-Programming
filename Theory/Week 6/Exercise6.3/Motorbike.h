#ifndef _MOTORBIKE_H
#define _MOTORBIKE_H

const double FUEL_PER_100KM = 2;
const double BONUS_PER_10KG = 0.1;

class Motorbike {
private:
    double fuelRest;
    double productWeight;

public:
    Motorbike();

    Motorbike(const double f, const double p);

    bool increaseProduct(double weight);

    bool reduceProduct(double weight);

    bool increaseFuel(double fuel);

    void reduceFuel(double fuel);

    bool run(double distance);

    bool isEmpty();

    double getFuelRest();

    double getProductWeight();
};

#endif