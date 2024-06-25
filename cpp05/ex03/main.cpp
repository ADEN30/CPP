#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        Intern  someRandomIntern;
        AForm*   rrf;
		Bureaucrat b1("louis", 32);

        rrf = someRandomIntern.makeForm("robotomy", "Bender");
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
        delete rrf;
    }
	std::cout << "\n\e[0;33m";
    try {
        Bureaucrat bureaucrat("ash", 2); // error with 200
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
    
}