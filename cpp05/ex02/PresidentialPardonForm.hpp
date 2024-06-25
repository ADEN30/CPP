#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		PresidentialPardonForm();
    
    public:
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm&);
        ~PresidentialPardonForm();
        void    execute(const Bureaucrat&) const;
};

#endif