#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("DefaultCrate"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
  if (grade < 1)
    throw GradeTooLowExeption();
  else if (grade > 150)
    throw GradeTooHighExeption();
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
    throw GradeTooHighExeption();
  else
    std::cout << this->name << " is demoted grade " << ++(this->grade) << "." << std::endl;
}

void Bureaucrat::promote() {
  if (this->grade <= 1)
    throw GradeTooLowExeption();
  else
    std::cout << this->name << " is promoted grade " << --(this->grade) << ". Congratulation!!" << std::endl;
}

const char *Bureaucrat::GradeTooHighExeption::what() const throw() {
  return ("Bureaucrate: The number is too high");
}

const char *Bureaucrat::GradeTooLowExeption::what() const throw() {
  return ("Bureaucrate: The number is too low");
}

std::ostream&  operator<<(std::ostream& flux, const Bureaucrat& obj)
{
  flux << obj.getName() << " , bureaucrate grade " << obj.getGrade() << std::endl;
}