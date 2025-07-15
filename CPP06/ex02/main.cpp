#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(NULL)));

    // generate & identify several times
    for (int i = 0; i < 5; ++i) {
        Base* ptr = generate();
        std::cout << "identify(Base*): ";
        identify(ptr);
        std::cout << "identify(Base&): ";
        identify(*ptr);
        std::cout << '\n';
        delete ptr;
    }
    return 0;
}
