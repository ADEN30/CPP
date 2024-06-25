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
        static AForm* build(std::string);
        void    execute(const Bureaucrat&) const;
};

#endif