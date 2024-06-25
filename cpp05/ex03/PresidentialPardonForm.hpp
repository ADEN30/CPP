#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
    
    public:
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm&);
        ~PresidentialPardonForm();
        static AForm* build(std::string);
        void    execute(const Bureaucrat&) const;
};

#endif