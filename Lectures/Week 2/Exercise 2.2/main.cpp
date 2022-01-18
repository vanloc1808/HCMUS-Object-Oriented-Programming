#include <iostream>
#include "Monomial.h"
#include "DemoProcess.h"

int main()
{
    int contChoice = 1;
    while (contChoice == 1) {
        showMenu();
        int userChoice = 0;
        std::cout << "Enter the number that you want.\n";
        std::cin >> userChoice;
        while (userChoice <= 0 || userChoice > 9) {
            std::cout << "Invalid number. Please try another number.\n";
            std::cin >> userChoice;
        }
        switch (userChoice)
        {
        case 1:
            getCoefficientProcess();
            break;
        case 2:
            getExponentProcess();
            break;
        case 3:
            newCoefficientProcess();
            break;
        case 4:
            newExponentProcess();
            break;
        case 5:
            calculateProcess();
            break;
        case 6:
            generalDerivativeProcess();
            break;
        case 7:
            addProcess();
            break;
        case 8:
            multiplyProcess();
            break;
        case 9:
            compareProcess();
            break;
        }
        std::cout << "Enter 1 if you want to continue, enter another number if you don't. ";
        std::cin >> contChoice;
    }
    return 0;
}
