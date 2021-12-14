#include <iostream>
#include <vector>
#include "Figure.h"

int main() {
    std::vector<Figure*> figures;

    figures.push_back(new Line());
    figures.push_back(new Rectangle());
    figures.push_back(new Ellipse());
    figures.push_back(new Line());
    figures.push_back(new Rectangle());
    figures.push_back(new Rectangle());
    figures.push_back(new Ellipse());
    figures.push_back(new Ellipse());
    figures.push_back(new Ellipse());

    for (int i = 0; i  < figures.size(); i++) {
        figures[i]->draw();
    }

    return 0;
}