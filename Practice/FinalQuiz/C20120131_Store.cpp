//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include "C20120131_Store.h"

C20120131_Store::C20120131_Store() {

}

C20120131_Store::C20120131_Store(int id, std::string name, float area, float income) {
    this->_storeID = id;
    this->_storeName = name;
    this->_area = area;
    this->_totalIncome = income;
}

float C20120131_Store::totalCost() {
    float rent = this->rentingCost();

    float tax = this->tax() * this->_totalIncome;

    return rent + tax;
}


float C20120131_Store::rentingCost() {
    return this->_area * PRICE_UNIT;
}