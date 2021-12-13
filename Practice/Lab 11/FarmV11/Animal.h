#ifndef _ANIMAL_H_
#define _ANIMAL_H_

class Animal {
public:
    Animal() {

    }

    ~Animal() {

    }

    int bear();

    int giveMilk();

    void speak();
};

class Cow : public Animal {
public:
    Cow() : Animal() {

    }

    ~Cow() {

    }

    int bear();

    int giveMilk();

    void speak();
};

class Sheep : public Animal {
public:
    Sheep() : Animal() {

    }

    ~Sheep() {

    }

    int bear();

    int giveMilk();

    void speak();
};

class Goat : public Animal {
public:
    Goat() : Animal() {

    }

    ~Goat() {

    }

    int bear();

    int giveMilk();

    void speak();
};

#endif // _ANIMAL_H_