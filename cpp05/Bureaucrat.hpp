#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class   Bureaucrat{
    private:
    const std::string   name;
    int                 grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string, int);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();
        int getGrade();
        const std::string getName();
        void    demote();
        void    promote();
        class GradeTooHighExeption : public std::exception
        {
            public:
            const char* what() const throw();
        };
        class GradeTooLowExeption : public std::exception
        {
            const char* what() const throw();
        };
    


};

#endif