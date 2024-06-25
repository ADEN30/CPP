#include "AForm.hpp"

AForm::AForm() : name("defaltForm"), signe(0), rq_grade(150), ex_grade(150)
{
}

AForm::AForm(std::string name, int sign_grade, int ex_grade) : name(name), signe(0), rq_grade(sign_grade), ex_grade(ex_grade)
{
	if (sign_grade < 1 || ex_grade < 1)
	{
		std::cout << "We can't make a Form because ";
		throw GradeTooHighException();
	}
	else if (sign_grade > 150 || ex_grade > 150)
	{
		std::cout << "We can't make a Form because ";
		throw GradeTooLowException(); 
	}
	std::cout << name << " Form is Create." << std::endl; 
}

AForm::AForm(std::string name, std::string target, int sign_grade, int ex_grade) : name(name), target(target), signe(0), rq_grade(sign_grade), ex_grade(ex_grade)
{
	if (sign_grade < 1 || ex_grade < 1)
	{
		std::cout << "We can't make a Form because ";
		throw GradeTooHighException();
	}
	else if (sign_grade > 150 || ex_grade > 150)
	{
		std::cout << "We can't make a Form because ";
		throw GradeTooLowException(); 
	}
	std::cout << name << " Form is Create." << std::endl; 
}

AForm::AForm(const AForm& src) : name(src.name), rq_grade(src.rq_grade), ex_grade(src.ex_grade)
{
	*this = src;
}

AForm& AForm::operator=(const AForm& src) 
{
	this->signe = src.signe;
	return (*this);
}

AForm::~AForm()
{
	std::cout << this->getName() << " Form is Deleted." << std::endl;
}

const std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSign() const
{
	return (this->signe);
}

int	AForm::getSignGrade() const
{
	return (this->rq_grade);
}

int	AForm::getExGrade() const
{
	return (this->ex_grade);
}

const std::string	AForm::getTarget() const
{
	return (this->target);
}

const char* AForm::AFormAlreadySigned::what() const throw()
{
	return ("The form is already signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

void	AForm::beSigned(const Bureaucrat& obj)
{
	std::cout << "Can we sign the form " << name << "?" << std:: endl;
	if (signe)
		throw (AFormAlreadySigned());
	else if (obj.getGrade() > rq_grade)
		throw GradeTooLowException();
	else
	{
		std::cout << "Yes, of course!" << std::endl;
		this->signe = true;
	}
}

std::ostream& operator<<(std::ostream& out, const AForm& src)
{
	if (src.getSign())
		out << src.getName() << " Form is signed(" << src.getSign() << ")\nGrade to sign: " << src.getSignGrade() << "\t" << "Grade to execute: " << src.getExGrade() << std::endl;
	else
		out << src.getName() << " Form is not signed(" << src.getSign() << ")\nGrade to sign: " << src.getSignGrade() << "\t" << "Grade to execute: " << src.getExGrade() << std::endl;
	return (out);
}