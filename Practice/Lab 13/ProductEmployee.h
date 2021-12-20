#ifndef _PRODUCTEMPLOYEE_H_
#define _PRODUCTEMPLOYEE_H_

#include "Employee.h"

class ProductEmployee: public Employee {
private:
    int _productPrice;
    int _productCount;
public:
    ProductEmployee(std::string fullname, int price, int count) : Employee(fullname) {
        _productPrice = price;
        _productCount = count;
    }

    int CalcSalary();

    int CalcBonus();

    int CalcPenalty();

};

#endif // _PRODUCTEMPLOYEE_H_