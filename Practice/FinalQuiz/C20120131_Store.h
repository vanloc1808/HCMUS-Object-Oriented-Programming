//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#ifndef _STORE_H_
#define _STORE_H_

const float PRICE_UNIT = 2000;

#include <string>

class C20120131_Store {
protected:
    int _storeID;

    std::string _storeName;

    float _area;

    float _totalIncome;

public:
    C20120131_Store();

    C20120131_Store(int id, std::string name, float area, float income);

    virtual float totalCost();

    virtual float rentingCost();

    virtual float tax() = 0;
};

#endif // !_STORE_H_