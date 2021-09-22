#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Student.h"
#include "DemoProcess.h"

int main()
{
    int contChoice = 1;
    while (contChoice == 1) {
        showMenu();
        int userChoice = 0;
        std::cout << "Enter the number that you want.\n";
        std::cin >> userChoice;
        while (userChoice <= 0 || userChoice > 8) {
            std::cout << "Invalid number. Please try another number.\n";
            std::cin >> userChoice;
        }

        std::cin.ignore();

        switch (userChoice)
        {
        case 1:
            getFullNameProcess();
            break;
        case 2:
            getLiteratureProcess();
            break;
        case 3:
            getMathProcess();
            break;
        case 4:
            newNameProcess();
            break;
        case 5:
            newLiteratureProcess();
            break;
        case 6:
            newMathProcess();
            break;
        case 7:
            averageProcess();
            break;
        case 8:
            classifyProcess();
            break;
        }
        std::cout << "Enter 1 if you want to continue, enter another number if you don't. ";
        std::cin >> contChoice;
    }
    return 0;
}

