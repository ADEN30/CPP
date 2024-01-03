#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << this->type << "constructor is called.\n";
}
Cat::~Cat() { std::cout << this->type << "destructor is called.\n"; }
Cat &Cat::operator=(const Cat &src) {
  this->type = src.type;
  return *this;
}

void makeSound() { std::cout << "Meow!\n"; }
