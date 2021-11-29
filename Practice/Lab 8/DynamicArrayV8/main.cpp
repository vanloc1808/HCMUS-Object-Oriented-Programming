#include <iostream>
#include <climits>
#include "DynamicArray.h"

int main() {
    DynamicArray* arr = DynamicArray::Parse("5, 8, 12, 15, 612, 19");

    if (!arr) {
        std::cout << "Error parsing array\n";
    } else {
        std::cout << arr->toString() << "\n";

        delete arr;
    }

    arr = DynamicArray::TryParse("5, a, 12, 15, 612, 19");

    if (!arr) {
        std::cout << "Error parsing array\n";
    } else {
        std::cout << arr->toString() << "\n";

        delete arr;
    }

    return 0;
}