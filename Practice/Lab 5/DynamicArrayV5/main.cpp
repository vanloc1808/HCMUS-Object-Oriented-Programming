#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray a;
    
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    a.pushBack(4);
    std::cout << a.toString() << "\n";
    std::cout << a.getAt(1) << "\n";

    return 0;
}