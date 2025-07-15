#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class AForm;

class Bureaucrat {
    private:
        std::string name;
        int grade;
    public:
        class GradeTooHighException : public std::exception {
            const char* what() const throw() {
                return "Grade Too High!";
            }
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw() {
                return "Grade Too Low!";
            }
        };
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& f);
        void executeForm(const AForm& form) const;
};

std::ostream& operator <<(std::ostream& os, const Bureaucrat &b); 

#endif