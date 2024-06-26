#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

    public:
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ~ShrubberyCreationForm();
        static AForm* build(std::string);
        void execute(const Bureaucrat&) const;

};

#endif