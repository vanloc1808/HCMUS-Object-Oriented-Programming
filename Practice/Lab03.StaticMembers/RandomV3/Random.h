#ifndef _RANDOM_H
#define _RANDOM_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Random {
private:
    static int result;

public:
    Random() {
        Random::result = rand();
    }

    int next() {
        return Random::result;
    }

    int next(int maxValue) {
        return (Random::result % maxValue);
    }
};

#endif