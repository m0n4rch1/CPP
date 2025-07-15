#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "\n=== Bureaucrats ===\n";
    Bureaucrat alice("Alice", 1);      // Highest rank
    Bureaucrat bob("Bob", 140);        // Low rank
    Bureaucrat joe("Joe", 50);         // Medium rank

    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << joe << std::endl;

    std::cout << "\n=== Forms ===\n";
    ShrubberyCreationForm shrub("Backyard");
    RobotomyRequestForm robo("Marvin");
    PresidentialPardonForm pardon("Ford");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n=== Signing Forms ===\n";
    alice.signForm(shrub);   // OK
    joe.signForm(robo);      // OK
    alice.signForm(pardon);  // OK
    bob.signForm(pardon);    // FAIL

    std::cout << "\n=== Executing Forms ===\n";
    bob.executeForm(shrub);   // FAIL (grade too low)
    alice.executeForm(shrub); // OK

    joe.executeForm(robo);    // OK (50% chance success/fail)
    alice.executeForm(pardon); // OK

    std::cout << "\n=== Done ===\n";
    return 0;
}
