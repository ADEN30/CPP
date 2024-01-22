#include "Form.hpp"

Form::Form() : name("defaltForm"), signe(0), rq_grade(150), ex_grade(150)
{
}

Form::Form(std::string name, int sign_grade, int ex_grade) : name(name), signe(0), rq_grade(sign_grade), ex_grade(ex_grade)
{
    if (sign_grade < 1)
        throw GradeTooLowException();
    else if (sign_grade > 150)
        throw GradeTooHighException(); 
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
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("We can't to make a Form because the grade is too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("We can't to make a Form because the grade is too low");
}


std::ostream& operator<<(const std::ostream& out, const Form& src)
{
 
}