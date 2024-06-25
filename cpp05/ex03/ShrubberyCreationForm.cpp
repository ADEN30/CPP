#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137){
	std::cout << "ShrubberyCreationForm is called for the target: " << target << "."<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src)
{
	std::cout << "Constructor copy of ShrubberyCreationForm is called." << std::endl;
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
	(void)src;
	return (*this);
}

AForm* ShrubberyCreationForm::build(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShruberryCreationForm is Delete." << std::endl; 
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{

	if (executor.getGrade() < this->getExGrade())
	{
		std::string suffix = "_shrubbery";
		std::ofstream ofs((this->getTarget() + suffix).c_str());
		if (!ofs.is_open())
			throw std::ofstream::failure("We can't open the file.");
		else
		{	
			ofs << "               ,@@@@@@@," << std::endl;
			ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			ofs << "       |o|        | |         | |" << std::endl;
			ofs << "       |.|        | |         | |" << std::endl;
			ofs << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		}
		ofs.close();
	}
	else
	{
		std::cout << executor.getName() << "can't execute " << this->getName() << std::endl;
		throw GradeTooLowException();
	}
}