#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Employee.h"

class Manager: public Employee {
private:
    int _baseSalary;
    int _salaryFactor;
public:
    Manager(std::string fullname, int base, int factor): Employee(fullname){
        _baseSalary = base;
        _salaryFactor = factor;
    }

    int CalcSalary();

    int CalcBonus();

    int CalcPenalty();
};

#endif // _MANAGER_H_