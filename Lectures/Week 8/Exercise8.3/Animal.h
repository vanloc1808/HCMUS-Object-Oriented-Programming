#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>

class Animal {
public:
    virtual int getSpeed() = 0;

    virtual void showInfo() = 0;
};

class Panther : public Animal {
private:
    int speed = 100;

public:
    int getSpeed() {
        return this->speed;
    }

    void showInfo() {
        std::cout << "Panther ";
    }
};

class Antelope : public Animal {
private:
    int speed = 80;

public:
    int getSpeed() {
        return this->speed;
    }

    void showInfo() {
        std::cout << "Antelope ";
    }
};


class Lion : public Animal {
private:
    int speed = 70;

public:
    int getSpeed() {
        return this->speed;
    }

    void showInfo() {
        std::cout << "Lion ";
    }
};

class Dog : public Animal {
private:
    int speed = 60;

public:
    int getSpeed() {
        return this->speed;
    }

    void showInfo() {
        std::cout << "Dog ";
    }
};

class HomoSapiens : public Animal {
private:
    int speed = 30;

public:
    int getSpeed() {
        return this->speed;
    }

    void showInfo() {
        std::cout << "Human ";
    }
};

class Horse : public Animal {
private:
    int speed = 60;

public: 
    int getSpeed() {
        return this->speed;
    }

    void showInfo() {
        std::cout << "Horse ";
    }

};

void compareSpeed(Animal* a1, Animal* a2) {
    if (a1->getSpeed() > a2->getSpeed()) {
        a1->showInfo();
        std::cout << "is faster than ";
        a2->showInfo();
    } else if (a1->getSpeed() < a2->getSpeed()) {
        a2->showInfo();
        std::cout << "is faster than ";
        a1->showInfo();
    } else {
        a1->showInfo();
        std::cout << "is equal to ";
        a2->showInfo();
    }
    
    std::cout << "\n";
}

#endif