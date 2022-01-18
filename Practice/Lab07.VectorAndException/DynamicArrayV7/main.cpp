#include <iostream>
#include <climits>
#include "DynamicArray.h"

int main() {
    DynamicArray a;
    
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    a.pushBack(4);
    std::cout << a.toString() << "\n";
    std::cout << a.getAt(1) << "\n";
    int x = a.getAt(6);
    if (x != INT_MIN) {
        std::cout << x << "\n";
    }

    return 0;
}