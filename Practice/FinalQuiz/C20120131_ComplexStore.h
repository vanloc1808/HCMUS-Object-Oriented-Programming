//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#ifndef _COMPLEXSTORE_H
#define _COMPLEXSTORE_H

#include <vector>
#include "C20120131_Store.h"

class C20120131_ComplexStore {
private:
    int _storeID;

    std::string _compleStoreName;

    std::vector<C20120131_Store*> _storeList;

public:
    C20120131_ComplexStore(int id, std::string name);

    ~C20120131_ComplexStore();

    void addStore(C20120131_Store* store);

    void removeStore(C20120131_Store* store);

    void removeStore(int index);

    float totalCost();

};

#endif // !_COMPLEXSTORE_H