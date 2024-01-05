#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << this->type << "Cat constructor is called.\n";
}
Cat::Cat(const Cat& copy) : Animal(copy)
{
  *this = copy;
  std::cout << "Cat constructor copy called\n";
}
Cat::~Cat() { std::cout << this->type << "Cat destructor is called.\n"; }

Cat &Cat::operator=(const Cat &src) {
  this->type = src.type;
  std::cout << "Cat assignement called\n";
  return *this;
}

std::string Cat::gettype()
{
 return (this->type);
}

void Cat::makeSound() { std::cout << "Meow!\n"; }
