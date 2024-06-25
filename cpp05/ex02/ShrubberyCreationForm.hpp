#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ~ShrubberyCreationForm();
        void execute(const Bureaucrat&) const;

};

#endif