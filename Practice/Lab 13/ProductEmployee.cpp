#include "ProductEmployee.h"

int ProductEmployee::CalcSalary(){
        return _productPrice * (_productCount- 100);
}

int ProductEmployee::CalcBonus() {
        if (_productCount > 100) {
                return 500 * _productCount;
        }

        return 0;
}

int ProductEmployee::CalcPenalty() {
        if (_productCount < 100) {
                return 600 * (100 - _productCount);
        }

        return 0;
}