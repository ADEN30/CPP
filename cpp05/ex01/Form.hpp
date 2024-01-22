#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

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
		std::string getName() const;
		bool	getSign();
		const int getSignGrade() const;
		const int getExGrade() const;
	
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	
};

std::ostream& operator<<(const std::ostream& out, const Form& src);

#endif