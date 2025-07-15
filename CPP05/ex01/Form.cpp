#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other) {
        this->name = other.name;
        this->gradeToSign = other.gradeToSign;
        this->gradeToExecute = other.gradeToExecute;
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const {return isSigned; }
int Form::getGradeToExecute() const { return gradeToExecute; }
int Form::getGradeToSign() const { return gradeToSign; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign )
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator <<(std::ostream& os, const Form& f)
{
    os << "Form \"" << f.getName() << "\", signed: " << std::boolalpha << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}