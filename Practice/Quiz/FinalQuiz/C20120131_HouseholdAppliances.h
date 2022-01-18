//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#ifndef _HOUSEHOLDAPPLIANCES_H_
#define _HOUSEHOLDAPPLIANCES_H_

#include "C20120131_Store.h"

class C20120131_HouseholdAppliances : public C20120131_Store {
private:

public:
    C20120131_HouseholdAppliances() : C20120131_Store() {};

    C20120131_HouseholdAppliances(int id, std::string name, float area, float income) : C20120131_Store(id, name, area, income) {};

    float tax();
};

#endif // !_HOUSEHOLDAPPLIANCES_H_