#include <iostream>
#include "Array.h"
#include "DemoProcess.h"

int main()
{
    int contChoice = 1;
    while (contChoice == 1) {
        showMenu();
        int userChoice = 0;
        std::cout << "Enter the number that you want.\n";
        std::cin >> userChoice;
        while (userChoice <= 0 || userChoice > 6) {
            std::cout << "Invalid number. Please try another number.\n";
            std::cin >> userChoice;
        }

        std::cin.ignore();

        switch (userChoice)
        {
        case 1:
            getSizeProcess();
            break;
        case 2:
            getElementProcess();
            break;
        case 3:
            newValueProcess();
            break;
        case 4:
            findProcess();
            break;
        case 5:
            sortAsc();
            break;
        case 6:
            sortDes();
            break;
        }
        std::cout << "Enter 1 if you want to continue, enter another number if you don't. ";
        std::cin >> contChoice;
    }
    return 0;
}


