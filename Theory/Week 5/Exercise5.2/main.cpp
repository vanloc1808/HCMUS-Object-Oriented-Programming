#include <iostream>
#include "Polynomial.h"

int Polynomial::cnt = 0;

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
    std::cout << ps;

     Polynomial pd = pa - pb;
     std::cout << pd;

     Polynomial pp = pa * pb;
     std::cout << pp;

     Polynomial pq = pa / pb;
     std::cout << pq;

    return 0;
}