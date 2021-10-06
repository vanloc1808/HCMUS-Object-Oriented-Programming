#include <iostream>
#include "Array.h"

int main() {
    // Array<int> a;

    // std::cin >> a;

    // std::cout << a;

    int* arr;
    int n;
    std::cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    Array<int> a(arr, n);

    std::cout << a << "\n";

    return 0;
}