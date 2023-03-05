#include "io.h"
#include <iostream>

int readNumber() {
    int x{};
    std::cin >> x;
    return x;
}

void writeAnswer(int x) {
    std::cout << "Result of the sum is " << x << "\n";
    return;
}