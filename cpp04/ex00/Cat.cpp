#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat constructor is called.\n"; }
Cat::Cat(const Cat &copy) : Animal(copy) {
  *this = copy;
  std::cout << "Cat constructor copy called\n";
}
Cat::~Cat() { std::cout << "Cat destructor is called.\n"; }

Cat &Cat::operator=(const Cat &src) {
  this->type = src.type;
  std::cout << "Cat assignement called\n";
  return *this;
}

void Cat::makeSound() { std::cout << "Meow!\n"; }
