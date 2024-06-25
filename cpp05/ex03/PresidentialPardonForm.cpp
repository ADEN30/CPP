#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "PresidentialPardonForm constructor is called for the target: " << target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src)
{
	std::cout << "PresidentialPardonForm copy is called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor is called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	(void)src;
	std::cout << "PresientialPardonForm assignement is called." << std::endl;
	return (*this);
}
AForm* PresidentialPardonForm::build(std::string target)
{
	return (new PresidentialPardonForm(target));
}
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() < this->getExGrade())
		std::cout << this->getTarget() << " is pardonned by Zaphod Beeblebrox." << std::endl;
	else
	{
		std::cout << executor.getName() << "can't execute " << this->getName() << std::endl;
		throw GradeTooLowException();
	}
}