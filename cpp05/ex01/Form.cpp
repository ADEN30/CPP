#include "Form.hpp"

Form::Form() : name("defaultForm"), signe(0), rq_grade(150), ex_grade(150)
{
}

Form::Form(std::string name, int sign_grade, int ex_grade) : name(name), signe(0), rq_grade(sign_grade), ex_grade(ex_grade)
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

Form::Form(const Form& src) : name(src.name), rq_grade(src.rq_grade), ex_grade(src.ex_grade)
{
	*this = src;
}

Form& Form::operator=(const Form& src) 
{
	this->signe = src.signe;
	return (*this);
}

Form::~Form()
{
	std::cout << this->getName() << " Form is Deleted." << std::endl;
}

const std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getSign() const
{
	return (this->signe);
}

int	Form::getSignGrade() const
{
	return (this->rq_grade);
}

int	Form::getExGrade() const
{
	return (this->ex_grade);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

void	Form::beSigned(const Bureaucrat& obj)
{
	std::cout << "Can we sign the Form ?" << std:: endl;
	if (obj.getGrade() > this->getSignGrade())
	{
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "Yes, of course!" << std::endl;
		this->signe = true;
	}
}

std::ostream& operator<<(std::ostream& out, const Form& src)
{
	if (src.getSign())
		out << src.getName() << " Form is signed(" << src.getSign() << ")\nGrade to sign: " << src.getSignGrade() << "\t" << "Grade to execute: " << src.getExGrade() << std::endl;
	else
		out << src.getName() << " Form is not signed(" << src.getSign() << ")\nGrade to sign: " << src.getSignGrade() << "\t" << "Grade to execute: " << src.getExGrade() << std::endl;
	return (out);
}