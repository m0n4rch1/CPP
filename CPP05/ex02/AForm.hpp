#ifndef AForm_HPP
# define AForm_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
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

        class NotSignedException : public std::exception {
            const char* what() const throw() {
                return "Form not signed!";
            }
        };

        AForm(const std::string& name, int gradeToSign, int GradeToExecute);
        ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &b);
        void executeCheck(const Bureaucrat& b) const;

        virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif