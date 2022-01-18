#include "Random.h"

int Random::result = 0;

int main() {
    Random r;

    std::vector<int> v = r.generateVector();

    std::cout << "Vector size: " << v.size() << "\n";
    for (int i = 0 ; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    r.getPosition(v);
}