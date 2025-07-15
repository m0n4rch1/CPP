#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade(); // should go to 1
        std::cout << a << std::endl;
        a.incrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;
        b.decrementGrade(); // should go to 150
        std::cout << b << std::endl;
        b.decrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 0); // should throw on creation
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
