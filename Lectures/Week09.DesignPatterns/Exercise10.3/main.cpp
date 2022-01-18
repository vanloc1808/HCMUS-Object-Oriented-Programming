#include <iostream>
#include "Staff.h"
#include "Company.h"

int main() {
    Company c;
    std::cout << "Input a company\n";
    std::cout << "First, input the number of staffs\n";
    std::cout << "For each staff, enter 0 if that is producing staff, enter another number if that is office staff\n";
    std::cout << "With producing staff, enter full name, year started to work, the number of products, each in a seperate line\n";
    std::cout << "With office staff, enter full name, year started to work, salary level and the number of day-offs, each in a seperate line\n";
    std::cout << "Unit: 1000 dong\n";

    c.input();

    std::cout << "Total salary: " << c.totalSalary() << " thousand dong \n";

    return 0;
}