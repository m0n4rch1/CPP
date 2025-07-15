#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other) {
        this->name = other.name;
        this->gradeToSign = other.gradeToSign;
        this->gradeToExecute = other.gradeToExecute;
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const {return isSigned; }
int AForm::getGradeToExecute() const { return gradeToExecute; }
int AForm::getGradeToSign() const { return gradeToSign; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign )
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::executeCheck(const Bureaucrat& b) const {
    if (!isSigned) throw NotSignedException();
    if (b.getGrade() > gradeToExecute) throw GradeTooLowException();
}

std::ostream& operator <<(std::ostream& os, const AForm& f)
{
    os << "Form \"" << f.getName() << "\", signed: " << std::boolalpha << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}