#include <iostream>
#include <cmath>
#include <climits>
#include "Random.h"

std::vector<int> Random::generateVector() {
    int size = next();
    while (size == 0) {
        size = next();
    }

    size = size % 32767;

    std::vector<int> v;

    for (int i = 0; i < size; i++) {
        int x = next();
        v.push_back(x);
    }

    return v;
}

void Random::getPosition(std::vector<int> v) {
    int pos = next();

    std::cout << "Position: " << pos << "\n";

    try
    {
        if (pos >= v.size() || pos < 0) {
            throw "Index out of bound";
        } else {
            std::cout << "Element: " << v[pos] << "\n";
        }
    }
    catch(const char* message)
    {
        std::cout << message << "\n";
    }
    
}