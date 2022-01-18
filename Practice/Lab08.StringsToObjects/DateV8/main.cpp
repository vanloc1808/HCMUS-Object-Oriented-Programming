#include <iostream>
#include <ctime>
#include "DateV5.h"

int main() {
    Date* d = Date::Parse("18/8/2002");

    if (!d) {
        std::cout << "Error parsing the date\n";
    } else {
        std::cout << "Date: " << d->toString() << "\n";

        delete d;
    }

    Date* d1 = Date::TryParse("2a/08/2002");

    if (!d1) {
        std::cout << "Error.\n";
    } else {
        std::cout << "Date: " << d1->toString() << "\n";

        delete d1;
    }

    return 0;
}