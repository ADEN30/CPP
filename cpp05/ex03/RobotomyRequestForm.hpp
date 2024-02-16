#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{  
    private:
        RobotomyRequestForm& operator=(const RobotomyRequestForm&);
    public:
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm&);
        ~RobotomyRequestForm();
        void    execute(const Bureaucrat&) const;
};

#endif