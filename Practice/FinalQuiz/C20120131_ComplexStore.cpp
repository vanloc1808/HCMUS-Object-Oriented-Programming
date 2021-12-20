//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include "C20120131_ComplexStore.h"

C20120131_ComplexStore::C20120131_ComplexStore(int id, std::string name) {
    this->_compleStoreName = name;
    this->_storeID = id;
}   

C20120131_ComplexStore::~C20120131_ComplexStore() {
    for (int i = 0; i < this->_storeList.size(); i++) {
        delete this->_storeList[i];
    }
}

void C20120131_ComplexStore::addStore(C20120131_Store* store) {
    this->_storeList.push_back(store);
}

void C20120131_ComplexStore::removeStore(C20120131_Store* store) {
    for (int i = 0; i < this->_storeList.size(); i++) {
        if (this->_storeList[i] == store) {
            this->_storeList.erase(this->_storeList.begin() + i);
            break;
        }
    }
}

void C20120131_ComplexStore::removeStore(int index) {
    this->_storeList.erase(this->_storeList.begin() + index);
}

float C20120131_ComplexStore::totalCost() {
    float totalCost = 0;

    for (int i = 0; i < this->_storeList.size(); i++) {
        totalCost += this->_storeList[i]->totalCost();
    }

    return totalCost;
}