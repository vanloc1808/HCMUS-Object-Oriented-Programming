#ifndef _DICE_H
#define _DICE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Dice {
public:
    int _rollCount;

public:
    Dice() {
        this->_rollCount = 0;
    }

    void roll() {
        int result = rand() % 6 + 1;

        std::cout << "Get the number: " << result << "\n";
        this->_rollCount++;
    }

};

#endif