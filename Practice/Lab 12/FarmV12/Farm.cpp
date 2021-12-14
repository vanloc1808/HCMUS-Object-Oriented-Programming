#include <iostream>
#include <vector>
#include "Farm.h"

Farm::Farm() {
    
}

Farm::Farm(const Farm& f) {
    for (int i = 0; i < f._animals.size(); i++) {
        if (typeid(*f._animals[i]) == typeid(Cow)) {
            this->_animals.push_back(new Cow());
        } else if (typeid(*f._animals[i]) == typeid(Sheep)) {
            this->_animals.push_back(new Sheep());
        } else if (typeid(*f._animals[i]) == typeid(Goat)) {
            this->_animals.push_back(new Goat());
        }
    }
}

Farm::~Farm() {
    for (int i = 0; i < this->_animals.size(); i++) {
        delete this->_animals[i];
    }
}

void Farm::addAnimal(Animal* a) {
    this->_animals.push_back(a);
}

void Farm::allSpeak() {
    for (int i = 0; i < this->_animals.size(); i++) {
        this->_animals[i]->speak();
    }
}

int Farm::allGiveBirth() {
    int ans = 0;
    int cows = 0;
    int sheeps = 0;
    int goats = 0;

    for (int i = 0; i < this->_animals.size(); i++) {
        ans += this->_animals[i]->giveBirth();

        if (typeid(*this->_animals[i]) == typeid(Cow)) {
            cows++;
        } else if (typeid(*this->_animals[i]) == typeid(Sheep)) {
            sheeps++;
        } else if (typeid(*this->_animals[i]) == typeid(Goat)) {
            goats++;
        }
    }

    for (int i = 0; i < cows; i++) {
        this->_animals.push_back(new Cow());
    }

    for (int i = 0; i < sheeps; i++) {
        this->_animals.push_back(new Sheep());
    }

    for (int i = 0; i < goats; i++) {
        this->_animals.push_back(new Goat());
    }

    return ans;
}

int Farm::allGiveMilk() {
    int ans = 0;
    
    for (int i = 0; i < this->_animals.size(); i++) {
        ans += this->_animals[i]->giveMilk();
    }

    return ans;
}