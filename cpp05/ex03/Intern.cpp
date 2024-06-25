#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern constructor is called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor is called." << std::endl;
}

AForm*  Intern::makeForm(std::string name, std::string target) const
{
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    AForm* (*form[])(std::string target) = {
        RobotomyRequestForm::build,
        PresidentialPardonForm::build,
        ShrubberyCreationForm::build};
    
    for ( int i(0); i < 3; i++ ) {
        if ( name == formNames[i] ) {
            std::cout << "Intern creates " << name << std::endl;
            return (*form[i])(target);
        }
    }
    std::cout << "Intern can not create " << name << " form" << std::endl;
    return NULL;
}