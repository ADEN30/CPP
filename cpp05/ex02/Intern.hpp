#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    private:
        Intern(const Intern&);
        Intern& operator=(const Intern&);
    public:
        Intern();
        ~Intern();
        AForm*  makeForm(std::string, std::string) const;
};

#endif