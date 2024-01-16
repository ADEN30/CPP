#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("DefaultCrate"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooLowExeption();
    else if (grade > 150)
        throw GradeTooHighExeption();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    this->grade = src.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

const std::string   Bureaucrat::getName()
{
    return (this->name);
}

void Bureaucrat::demote()
{
    if (this->grade >= 150)
        throw GradeTooHighExeption();
    else
        std::cout << this->name << " is demoted." << std::endl;
}

void Bureaucrat::promote()
{
    if (this->grade <= 150)
        throw GradeTooHighExeption();
    else
        std::cout << this->name << " is promoted. Congratulation !!" << std::endl;
}

const char* Bureaucrat::GradeTooHighExeption::what() const throw()
{
    return ("The number is too highter");
}

const char* Bureaucrat::GradeTooLowExeption::what() const throw()
{
    return ("The number is too lower");
}

