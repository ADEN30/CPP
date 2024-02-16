#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << "RobotmyRequestForm constructor is called for the target: " << target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src)
{
    std::cout << "RobotomyRequestForm copy is called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor is called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    (void)src;
    std::cout << "RobotomyRequestForm assignement is called." << std::endl;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    std::time_t result;
    result = time(NULL);
    if (executor.getGrade() < this->getExGrade())
    {
        if (localtime(&result)->tm_sec % 2)
        {
            std::cout << this->getTarget() << " is robotomized succeccfully!" << std::endl;
        }
        else
            std::cout << this->getTarget() << " robotomized failed!" << std::endl;
    }
    else
    {
		std::cout << executor.getName() << "can't execute " << this->getName() << std::endl;
		throw GradeTooLowException();
    }
}