//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#ifndef _COSMETICS_H_
#define _COSMETICS_H_

#include "C20120131_Store.h"

class C20120131_Cosmetics : public C20120131_Store {
private:
    int _productTypeNumber;

public:
    C20120131_Cosmetics () : C20120131_Store() {};

    C20120131_Cosmetics (int id, std::string name, float area, float income, int productTypeNumber) : C20120131_Store(id, name, area, income) {
        this->_productTypeNumber = productTypeNumber;
    };

    float tax();

};

#endif // !_COSMETICS_H_