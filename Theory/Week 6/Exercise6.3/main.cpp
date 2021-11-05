#include <iostream>
#include "Truck.h"

int main() {
    Truck t(100, 0);
    t.increaseProduct(10000);

    std::cout << "Fuels rest: " << t.getFuelRest() << "\n";
    std::cout << "Weights of products: " << t.getProductWeight() << "\n";
    
    t.run(200);

    std::cout << "Fuels rest: " << t.getFuelRest() << "\n";
    std::cout << "Weights of products: " << t.getProductWeight() << "\n";

    return 0;

}