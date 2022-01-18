#include <iostream>
#include "NormalTheater.h"
#include "DeluxeTheater.h"

double NormalTheater::totalIncome = 0;

int main() {
    NormalTheater a(5, 6);
    int row = 1, column = 3;
    std::cout << "Normal theater\n";
    std::cout << "Price at row " << row + 1 << " and column " << column + 1 << " is : " << a.price(row, column) << "\n";

    if (a.bookSeat(row, column)) {
        std::cout << "Seat at row " << row + 1 << " and column " << column + 1 << " is booked successfully\n";
    } else { 
        std::cout << "Seat at row " << row + 1 << " and column " << column + 1 << " is not available\n"; 
    }

    DeluxeTheater b(5, 6);
    row = 2, column = 2;
    std::cout << "Deluxe theater\n";
     std::cout << "Price at row " << row + 1 << " and column " << column + 1 << " is : " << b.price(row, column) << "\n";

    if (b.bookSeat(row, column)) {
        std::cout << "Seat at row " << row + 1 << " and column " << column + 1 << " is booked successfully\n";
    } else { 
        std::cout << "Seat at row " << row + 1 << " and column " << column + 1 << " is not available\n"; 
    }

    return 0;
 }