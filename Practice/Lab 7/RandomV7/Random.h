#ifndef _RANDOM_H
#define _RANDOM_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class Random {
private:
    static int result;

public:
    Random() {
        Random::result = rand();
    }

    int next() {
        return rand();
    }

    std::vector<int> generateVector();

    void getPosition(std::vector<int> v);

    int next(int maxValue) {
        return (Random::result % maxValue);
    }
};

#endif