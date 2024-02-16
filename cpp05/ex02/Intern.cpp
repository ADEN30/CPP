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
    AForm*    forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
    
    for ( int i(0); i < 3; i++ ) {
        if ( name == formNames[i] ) {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i];
        }
    }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return NULL;
}