#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

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
        tm* ltm = localtime(&now);
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
            }
            else {
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

int main() {
    Company c;
    std::cout << "Input a company\n";
    std::cout << "First, input the number of staffs\n";
    std::cout << "For each staff, enter 0 if that is producing staff, enter another number if that is office staff\n";
    std::cout << "With producing staff, enter full name, year started to work, the number of products, each in a seperate line\n";
    std::cout << "With office staff, enter full name, year started to work, salary level and the number of day-offs, each in a seperate line\n";

    c.input();

    std::cout << "Total salary: " << c.totalSalary() << "\n";

    return 0;
}