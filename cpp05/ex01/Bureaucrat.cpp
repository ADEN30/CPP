#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("DefaultCrate"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
  if (grade < 1)
    throw GradeTooLowException();
  else if (grade > 150)
    throw GradeTooHighException();
  else {
    this->grade = grade;
    std::cout << this->name << " is created with grade " << this->grade << std::endl;
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) { 
  *this = src; 
  std::cout << "Copy consructor is calling" << std::endl;
  }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  this->grade = src.grade;
  std::cout << "Bureaucrat assignement operator is calling." << std::endl;
  return (*this);
}

Bureaucrat::~Bureaucrat() {
  std::cout << this->name << " Bureaucrate is Deleted." << std::endl;
}

int Bureaucrat::getGrade() const { return (this->grade); }

const std::string Bureaucrat::getName() const { return (this->name); }

void Bureaucrat::demote() {
  if (this->grade >= 150)
    throw GradeTooHighException();
  else
    std::cout << this->name << " is demoted grade " << ++(this->grade) << "." << std::endl;
}

void Bureaucrat::promote() {
  if (this->grade <= 1)
    throw GradeTooLowException();
  else
    std::cout << this->name << " is promoted grade " << --(this->grade) << ". Congratulation!!" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Bureaucrate: The number is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Bureaucrate: The number is too low");
}

void Bureaucrat::signForm(Form& obj)
{
  try
  {
    obj.beSigned(*this);
    std::cout << this->getName() << " signed " << obj.getName() << std::endl;
  } 
  catch(const std::exception &e){
    std::cout << this->getName() << "couldn't sign " << obj.getName() << " because Bureaucrate Grade is lower." << std::endl;
  }
}

std::ostream&  operator<<(std::ostream& flux, const Bureaucrat& obj)
{
  flux << obj.getName() << " , Bureaucrate grade " << obj.getGrade() << std::endl;
  return flux;
}
