//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#ifndef _FOOD_H_
#define _FOOD_H_

#include <string>
#include "C20120131_Store.h"

class C20120131_Food : public C20120131_Store {
private:

public:
    C20120131_Food() : C20120131_Store() {};

    C20120131_Food(int id, std::string name, float area, float income) : C20120131_Store(id, name, area, income)  {
    
    };

    float tax();
};

#endif // !_FOOD_H_