#include <iostream>

int main() {
    // These 3 below are same thing:
    // void *ptr1 = 0;
    // void *ptr2 = NULL;
    // void *ptr3 = nullptr;

    int a = 5;
    void *ptr = &a; // '&' gives the memory address of a given variable
    std::cout << a << std::endl;
    std::cout << "Address=" << ptr << std::endl;

    return 0;
}
