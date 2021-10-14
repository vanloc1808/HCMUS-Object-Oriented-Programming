#include <iostream>
#include "Polynomial.h"

int main() {
    double* a = new double[5];
    for (int i = 0; i < 5; i++) {
        a[i] = 1;
    }

    double* b = new double[3];
    for (int i = 0; i < 3; i++) {
        b[i] = i + 1;
    }

    Polynomial pa(4, a);
    Polynomial pb(2, b);

    Polynomial ps = pa + pb;
    for (int i = 0; i <= ps.getDegree(); i++) {
        std::cout << ps.getCoefficient(ps.getDegree() - i) << " ";
    }
    std::cout << "\n";

    // Polynomial pd = pa - pb;
    // for (int i = 0; i <= pd.getDegree(); i++) {
    //     std::cout << pd.getCoefficient(i) << " ";
    // }
    // std::cout << "\n";

    // Polynomial pp = pa * pb;
    // for (int i = 0; i <= pp.getDegree(); i++) {
    //     std::cout << pp.getCoefficient(i) << " ";
    // }
    // std::cout << "\n";

    // Polynomial pq = pa / pb;
    // for (int i = 0; i <= pq.getDegree(); i++) {
    //     std::cout << pq.getCoefficient(i) << " ";
    // }
    // std::cout << "\n";

    return 0;
}