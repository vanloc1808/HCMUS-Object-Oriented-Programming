#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <iostream>
#include <string>
#include <vector>
#include "Staff.h"

class Company {
private:
    std::vector<Staff*> staffList;

public:
    void input() {
        int n;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;

            Staff* s;

            if (x == 0) {
                s = new producingStaff();
            } else {
                s = new officeStaff();
            }

            s->input();

            this->staffList.push_back(s);

        }
    }

    float totalSalary() {
        float sum = 0;
        
        for (int i = 0; i < this->staffList.size(); i++) {
            sum += this->staffList[i]->salary();
        }

        return sum;
    }
};

#endif // _COMPANY_H_