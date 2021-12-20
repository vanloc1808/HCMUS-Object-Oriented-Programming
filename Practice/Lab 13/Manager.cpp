#include "Manager.h"

int Manager::CalcSalary(){
        return _baseSalary * _salaryFactor;
}

int Manager::CalcBonus() {
    return 0;
}

int Manager::CalcPenalty() {
    return 0;
}