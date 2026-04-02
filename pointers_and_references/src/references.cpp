#include "main.hpp"
#include <iostream>

void increment(int &value) { value++; }

void referencesFunc() {
    int x = 5;
    increment(x);
    // x is now 6
    std::cout << x << std::endl;
}
