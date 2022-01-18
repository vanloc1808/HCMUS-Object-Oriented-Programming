#ifndef _STAFF_H_
#define _STAFF_H_

#include <iostream>
#include <string>
#include <ctime>

const int ALLOWANCE = 500;
const int BONUS_ALLOWANCE_PER_YEAR = 50;

class Staff {
protected:
    std::string name;
    int year;

public:
    virtual void input() {
        std::cin.ignore();
        std::getline(std::cin, this->name);
        std::cin >> this->year;
    }

    virtual float salary() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        return ALLOWANCE + BONUS_ALLOWANCE_PER_YEAR * (currentYear - this->year);
    }
};

class producingStaff : public Staff {
private:
    int production;

public:
    void input() {
        Staff::input();
        std::cin >> this->production;
    }

    float salary() {
        return Staff::salary() + 1.00 * this->production * 10;
    }
};

class officeStaff : public Staff {
private:
    float salaryLevel;

    int dayoff;

public:
    void input() {
        Staff::input();
        std::cin >> this->salaryLevel;
        std::cin >> this->dayoff;
    }

    float salary() {
        return Staff::salary() + 1.00 * this->salaryLevel - 1.00 * this->dayoff * 10;
    }

};

#endif // _STAFF_H_