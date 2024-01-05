#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  this->ide = new Brain();
  std::cout << this->type << "Cat constructor is called.\n";
}
Cat::Cat(const Cat &copy) : Animal(copy) {
  *this = copy;
  std::cout << "Cat constructor copy called\n";
}
Cat::~Cat() {
  delete this->ide;
  std::cout << this->type << "Cat destructor is called.\n";
}

Cat &Cat::operator=(const Cat &src) {
  this->type = src.type;
  this->ide = new Brain(*src.ide);
  std::cout << "Cat assignement called\n";
  return *this;
}

void Cat::makeSound() { std::cout << "Meow!\n"; }
