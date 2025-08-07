#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    try {
        std::vector<int>::iterator it = easyfind(numbers, 30);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(numbers, 100);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
    