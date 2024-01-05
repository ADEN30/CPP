#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "Dog constructor is called.\n"; }
Dog::Dog(const Dog &copy) : Animal(copy) {
  *this = copy;
  std::cout << "Dog constructor copy called\n";
}
Dog::~Dog() { std::cout << "Dog destructor is called.\n"; }

Dog &Dog::operator=(const Dog &src) {
  this->type = src.type;
  std::cout << "Dog assignement called\n";
  return *this;
}

void Dog::makeSound() { std::cout << "Wouaf!\n"; }
