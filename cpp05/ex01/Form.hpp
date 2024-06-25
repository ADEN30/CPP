#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool		signe;
		const int	rq_grade;
		const int	ex_grade;
		Form();
	public:
		Form(std::string, int, int);
		Form(const Form&);
		~Form();
		Form&	operator=(const Form&);
		const std::string getName() const;
		bool	getSign() const;
		int getSignGrade() const;
		int getExGrade() const;
		void	beSigned(const Bureaucrat&);
	
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class FormAlreadySigned : public std::exception
	{
		const char* what() const throw();
	};
	
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif