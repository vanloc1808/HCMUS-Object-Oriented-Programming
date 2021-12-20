//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include "C20120131_HouseholdAppliances.h"

float C20120131_HouseholdAppliances::tax() {
    if (this->_totalIncome < 5000) {
        return 0.2;
    }

    return 0.3;
}