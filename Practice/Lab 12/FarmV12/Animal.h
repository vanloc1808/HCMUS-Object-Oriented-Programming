#ifndef _ANIMAL_H_
#define _ANIMAL_H_

class Animal {
private:

public:
    Animal() {

    }

    ~Animal() {

    }

    virtual int giveMilk() = 0;

    virtual int giveBirth() = 0;

    virtual void speak() = 0;
};

class Cow : public Animal {
private:

public:
    Cow() : Animal() {

    }

    ~Cow();

    int giveMilk();

    int giveBirth();

    void speak();
};

class Sheep : public Animal {
private:

public:
    Sheep() : Animal() {

    }

    ~Sheep();

    int giveMilk();

    int giveBirth();

    void speak();
};

class Goat : public Animal {
private:

public:
    Goat() : Animal() {

    }

    ~Goat();
    
    int giveMilk();

    int giveBirth();

    void speak();
};

#endif