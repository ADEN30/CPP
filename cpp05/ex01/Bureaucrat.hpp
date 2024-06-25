#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class   Bureaucrat{
    private:
    const std::string   name;
    int                 grade;
    Bureaucrat();

    public:
        Bureaucrat(const std::string, int);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();
        int getGrade() const;
        const std::string getName() const;
        void    demote();
        void    promote();
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

        void signForm(Form&);
};

std::ostream&   operator<<(std::ostream&, const Bureaucrat&);

#endif