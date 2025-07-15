#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 30);
        Form taxForm("Tax Form", 40, 20);

        std::cout << taxForm << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat bob("Bob", 50);
        Form secretForm("Secret Doc", 30, 20);
        bob.signForm(secretForm); // should fail

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
