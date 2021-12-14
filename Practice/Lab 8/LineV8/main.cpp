#include <iostream>
#include "Point.h"
#include "Line.h"

int Point::instanceCount = 0;
int Line::instanceCount = 0;
int main() {
    
    Line* line = Line::Parse("(1, 2), (3, 4)");

    std::cout << line->length() << "\n";

    std::cout << line->toString() << "\n";

    delete line;

    return 0;

}
