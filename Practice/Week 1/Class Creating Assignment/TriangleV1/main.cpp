#include <iostream>
#include "Triangle.h"

int main() {
    Point a(1, 1);
    Point b(3, 1);
    Point c(3, 3);

    Triangle t(a, b, c);

    Point* oldVertices = t.getVertices();
    std::cout << "Old vertices: ";
    for (int i = 0; i < 3; i++) {
        oldVertices[i].output();
        std::cout << " ";
    }
    std::cout << "\n";

    Point e(4, 1);
    Point f(4, 7);
    oldVertices[1] = e;
    oldVertices[2] = f;

    t.setVertices(oldVertices);

    Point* newVertices = t.getVertices();
    std::cout << "Old vertices: ";
    for (int i = 0; i < 3; i++) {
        newVertices[i].output();
        std::cout << " ";
    }
    std::cout << "\n";
}