#ifndef _FARM_H_
#define _FARM_H_

#include <vector>
#include "Animal.h"

class Farm {
private:
    std::vector<Animal*> _animals;

public:
    Farm();

    Farm(const Farm& f);

    ~Farm();

    void addAnimal(Animal* a);

    void allSpeak();

    int allGiveBirth();

    int allGiveMilk();

};

#endif // _FARM_H_