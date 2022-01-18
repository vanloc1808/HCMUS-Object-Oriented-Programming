//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include "C20120131_MBMarket.h"

C20120131_MBMarket::C20120131_MBMarket() {

}

C20120131_MBMarket::~C20120131_MBMarket() {
    for (int i = 0; i < this->_storeList.size(); i++) {
        delete this->_storeList[i];
    }

    for (int i = 0; i < this->_complexStoreList.size(); i++) {
        delete this->_complexStoreList[i];
    }
}

void C20120131_MBMarket::addStore(C20120131_Store* store) {
    this->_storeList.push_back(store);
}

void C20120131_MBMarket::removeStore(C20120131_Store* store) {
    for (int i = 0; i < this->_storeList.size(); i++) {
        if (this->_storeList[i] == store) {
            this->_storeList.erase(this->_storeList.begin() + i);
            break;
        }
    }
}

void C20120131_MBMarket::removeStore(int index) {
    this->_storeList.erase(this->_storeList.begin() + index);
}

void C20120131_MBMarket::addComplexStore(C20120131_ComplexStore* store) {
    this->_complexStoreList.push_back(store);
}

void C20120131_MBMarket::removeComplexStore(C20120131_ComplexStore* store) {
    for (int i = 0; i < this->_complexStoreList.size(); i++) {
        if (this->_complexStoreList[i] == store) {
            this->_complexStoreList.erase(this->_complexStoreList.begin() + i);
            break;
        }
    }
}

void C20120131_MBMarket::removeComplexStore(int index) {
    this->_complexStoreList.erase(this->_complexStoreList.begin() + index);
}

float C20120131_MBMarket::totalCost() {
    float totalCost = 0;

    for (int i = 0; i < this->_storeList.size(); i++) {
        totalCost += this->_storeList[i]->totalCost();
    }

    for (int i = 0; i < this->_complexStoreList.size(); i++) {
        totalCost += this->_complexStoreList[i]->totalCost();
    }

    return totalCost;
}