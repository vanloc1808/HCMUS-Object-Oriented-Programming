#ifndef _DAILYEMPLOYEE_H_
#define _DAILYEMPLOYEE_H_

#include "Employee.h"

class DailyEmployee: public Employee {
private:
    int _dayCount;
    int _dailyPrice;
public:
    DailyEmployee(std::string fullname, int price, int count): Employee(fullname){
        _dailyPrice = price;
        _dayCount = count;
    }

    int CalcSalary();

    int CalcBonus();

    int CalcPenalty();
};

#endif // _DAILYEMPLOYEE_H_