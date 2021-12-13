#include "Farm.h"

Farm::Farm() {

}

Farm::~Farm() {

}

void Farm::addCow(Cow cow) {
    this->_cows.push_back(cow);
}

void Farm::addSheep(Sheep sheep) {
    this->_sheeps.push_back(sheep);
}

void Farm::addGoat(Goat goat) {
    this->_goats.push_back(goat);
}

void Farm::allSpeak() {
    for (int i = 0; i < this->_cows.size(); i++) {
        this->_cows[i].speak();
    }

    for (int i = 0; i < this->_sheeps.size(); i++) {
        this->_sheeps[i].speak();
    }

    for (int i = 0; i < this->_goats.size(); i++) {
        this->_goats[i].speak();
    }
}

int Farm::allBabies() {
    int ans = 0;

    for (int i = 0; i < this->_cows.size(); i++) {
        ans += this->_cows[i].bear();
    }

    for (int i = 0; i < this->_sheeps.size(); i++) {
        ans += this->_sheeps[i].bear();
    }

    for (int i = 0; i < this->_goats.size(); i++) {
        ans += this->_goats[i].bear();
    }

    return ans;
}

int Farm::allMilk() {
    int ans = 0;

    for (int i = 0; i < this->_cows.size(); i++) {
        ans += this->_cows[i].giveMilk();
    }

    for (int i = 0; i < this->_sheeps.size(); i++) {
        ans += this->_sheeps[i].giveMilk();
    }

    for (int i = 0; i < this->_goats.size(); i++) {
        ans += this->_goats[i].giveMilk();
    }

    return ans;
}