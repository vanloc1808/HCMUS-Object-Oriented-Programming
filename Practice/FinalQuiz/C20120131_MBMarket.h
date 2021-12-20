//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include <vector>
#include "C20120131_Store.h"
#include "C20120131_Food.h"
#include "C20120131_Cosmetics.h"
#include "C20120131_HouseholdAppliances.h"
#include "C20120131_ComplexStore.h"

class C20120131_MBMarket {
private:
    std::vector<C20120131_Store*> _storeList;
    std::vector<C20120131_ComplexStore*> _complexStoreList;

public:
    C20120131_MBMarket();

    ~C20120131_MBMarket();

    void addStore(C20120131_Store* store);

    void removeStore(C20120131_Store* store);

    void removeStore(int index);

    void addComplexStore(C20120131_ComplexStore* store);

    void removeComplexStore(C20120131_ComplexStore* store);

    void removeComplexStore(int index);
    
    float totalCost();
};