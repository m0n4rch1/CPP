#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
    executeCheck(b);
    std::ofstream file(target + "_shrubbery");
    file << "ASCII TREE" << std::endl;
    file.close();
}