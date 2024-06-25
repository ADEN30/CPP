#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const std::string target;
		bool		signe;
		const int	rq_grade;
		const int	ex_grade;
		AForm();
	public:
		AForm(std::string, int, int);
		AForm(std::string, std::string, int, int);
		AForm(const AForm&);
		virtual ~AForm();
		AForm&	operator=(const AForm&);
		const std::string getName() const;
		bool	getSign() const;
		int getSignGrade() const;
		int getExGrade() const;
		const std::string getTarget() const;
		void	beSigned(const Bureaucrat&);
		virtual void	execute(const Bureaucrat&) const = 0;
	
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class AFormAlreadySigned : public std::exception
	{
		const char* what() const throw();
	};
	
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif