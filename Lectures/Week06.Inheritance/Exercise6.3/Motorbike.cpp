#include <iostream>
#include "Motorbike.h"

//default constructor
Motorbike::Motorbike() {
    this->fuelRest = 0;
    this->productWeight = 0;
}

//fully-parameterized constructor
Motorbike::Motorbike(const double f, const double p) {
    this->fuelRest = f;
    this->productWeight = p;
}

//add weight kg to the motorbike
//weight must be nonnegative
bool Motorbike::increaseProduct(double weight) {
    if (weight >= 0) {
        this->productWeight += weight;
        std::cout << "Added " << weight << " kilograms.\n";

        return true;
    } 

    std::cout << "Cannot add! Minus weight!\n";

    return false;
}

//get weight kg from the motorbike
//weight must be nonnegative
bool Motorbike::reduceProduct(double weight) {
    if (weight >= 0 && weight <= this->productWeight) {
        this->productWeight -= weight;
        std::cout << "Got " << weight << " kilograms.\n";

        return true;
    }

    std::cout << "Cannot get! Minus weight or not enough product!\n";

    return false;
}

//add fuel liters to the motorbike
//fuel must be nonnegative
bool Motorbike::increaseFuel(double fuel) {
    if (fuel >= 0) {
        this->fuelRest += fuel;
        std::cout << "Added " << fuel << "liters.\n";

        return true;
    }
    std::cout << "Cannot add! Minus amount of fuel!\n";

    return false;
}

//this function is used only when we identify that there is ENOUGH fuel to reduce
void Motorbike::reduceFuel(double fuel) {
    this->fuelRest -= fuel;
}

//run distance km
//check if the fuel is enough
bool Motorbike::run(double distance) {
    double fuelNeed = (distance / 100) * FUEL_PER_100KM + (distance / 100) * (this->productWeight / 10) * BONUS_PER_10KG;

    if (fuelNeed > this->fuelRest) {
        std::cout << "Cannot run! Not enough fuel!\n";

        return false;
    } 

    std::cout << "Run " << distance << " kilometers.\n";

    this->reduceFuel(fuelNeed);

    return true;
}

bool Motorbike::isEmpty() {
    return (this->fuelRest == 0);
}

double Motorbike::getFuelRest() {
    return this->fuelRest;
}

double Motorbike::getProductWeight() {
    return this->productWeight;
}