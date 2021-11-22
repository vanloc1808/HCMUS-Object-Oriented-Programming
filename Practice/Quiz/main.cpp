#include <iostream>
#include <ctime>
#include "TimeV5.h"

int main() {
    Time* t = new Time(12, 34, 56);

    t->decreaseHour(13);
    print(*t);
    t->decreaseMinute(59);
    print(*t);
    t->decreaseSecond(59);
    print(*t);

    delete t;

    return 0;
}