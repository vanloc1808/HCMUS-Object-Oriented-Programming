#ifndef _FARM_H_
#define _FARM_H_

#include <vector>
#include "Animal.h"

class Farm {
private:
    std::vector<Cow> _cows;

    std::vector<Sheep> _sheeps;

    std::vector<Goat> _goats;

public:
    Farm();

    ~Farm();

    void addCow(Cow cow);

    void addSheep(Sheep sheep);

    void addGoat(Goat goat);

    void allSpeak();

    int allBabies();

    int allMilk();

};

#endif