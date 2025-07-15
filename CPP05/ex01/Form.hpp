#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
    private:
        std::string name;
        bool isSigned;
        int gradeToSign;
        int gradeToExecute;

    public:
        class GradeTooHighException: public std::exception {
            const char* what() const throw() {
                return "Form grade too high!";
            }
        };

        class GradeTooLowException: public std::exception {
            const char* what() const throw() {
                return "Form grade too low!";
            }
        };

        Form(const std::string& name, int gradeToSign, int GradeToExecute);
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif