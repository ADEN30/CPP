#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	{
        Bureaucrat bureaucrat("ash", 2); 
		try {
	        ShrubberyCreationForm form1("Shrubbery");
	        RobotomyRequestForm form2("Robotomy");
	        PresidentialPardonForm form3("President");

	        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
	        bureaucrat.signForm(form1);
	        bureaucrat.executeForm(form1);
	        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
	        bureaucrat.signForm(form2);
	        bureaucrat.executeForm(form2);
	        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
	        bureaucrat.signForm(form3);
	        bureaucrat.executeForm(form3);
	    } catch (std::exception &e) {
	        std::cout << e.what() << std::endl;
	    } 
	}
	std::cout << "\n\e[0;31m";
	{
        Bureaucrat bureaucrat("ash", 34);
		try {
	        ShrubberyCreationForm form1("Shrubbery");
	        RobotomyRequestForm form2("Robotomy");
	        PresidentialPardonForm form3("President");

	        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
	        bureaucrat.signForm(form1);
	        bureaucrat.executeForm(form1);
	        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
	        bureaucrat.signForm(form2);
	        bureaucrat.executeForm(form2);;
	        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
	        bureaucrat.signForm(form3);
	        bureaucrat.executeForm(form3);
	    } catch (std::exception &e) {
	        std::cout << e.what() << std::endl;
	    }
	}
    return 0;
    
}