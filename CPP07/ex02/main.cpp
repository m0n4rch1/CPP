#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> emptyArr;
    std::cout << "emptyArr size: " << emptyArr.size() << std::endl;

    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = i * 10;
    std::cout << "numbers:";
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << " " << numbers[i];
    std::cout << std::endl;

    Array<int> copyArr = numbers;
    numbers[0] = 42;
    std::cout << "After modifying numbers[0]:" << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << ", copyArr[0] = " << copyArr[0] << std::endl;

    try {
        numbers[10] = 100;
    } catch (std::exception &e) {
        std::cout << "Exception caught: out of bounds" << std::endl;
    }

    std::cout << "copyArr size: " << copyArr.size() << std::endl;

    return 0;
}