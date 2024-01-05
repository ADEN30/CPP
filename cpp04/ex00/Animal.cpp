#include "Animal.hpp"

Animal::Animal() { std::cout << "Animal constructor is called.\n"; }
Animal::Animal(std::string str) : type(str) {
  std::cout << "Animal constructor is called.\n";
}

Animal::Animal(const Animal &src) {
  this->type = src.type;
  std::cout << "Animal copy constructor is called.\n";
}

Animal::~Animal() { std::cout << "Animal destructor is called.\n"; }

Animal &Animal::operator=(const Animal &src) {
  this->type = src.type;
  return (*this);
}
void Animal::makeSound() { std::cout << "Animal make all sound.\n"; }

std::string Animal::gettype()
{
	return this->type;
}
