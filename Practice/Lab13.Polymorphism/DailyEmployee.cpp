#include "DailyEmployee.h"

int DailyEmployee::CalcSalary(){
    return _dailyPrice * _dayCount;
}

int DailyEmployee::CalcBonus() {
    if (_dayCount > 20) {
        return 100000 * (_dayCount - 20);
    }
    
    return 0;
}

int DailyEmployee::CalcPenalty() {
    if (_dayCount < 15) {
        return 100000 * (15 - _dayCount);
    }
    
    return 0;
}