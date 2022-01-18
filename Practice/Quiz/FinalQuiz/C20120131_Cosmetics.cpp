//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include "C20120131_Cosmetics.h"

float C20120131_Cosmetics::tax() {
    if (this->_productTypeNumber < 100) {
        return 0.1;
    } 

    return 0.1 + 0.001 * (this->_productTypeNumber - 100);
}