#include <iostream>
#include <string>
#include "iter.hpp"

void print(const int& value) {
    std::cout << value << std::endl;
}

void print(const std::string& value) {
    std::cout << value << std::endl;
}

void increment(int& value) {
    ++value;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray:" << std::endl;
    ::iter(intArray, intLen, static_cast<void(*)(const int&)>(print));

    ::iter(intArray, intLen, increment);

    std::cout << "Incremented intArray:" << std::endl;
    ::iter(intArray, intLen, static_cast<void(*)(const int&)>(print));

    const std::string strArray[] = {"hello", "world", "42"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array:" << std::endl;
    ::iter(strArray, strLen, static_cast<void(*)(const std::string&)>(print));

    return 0;
}
