#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << this->type << " constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
  *this = copy;
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
  this->type = copy.type;
  std::cout << "WrongCat assignation operator called" << std::endl;
  return (*this);
}

WrongCat::~WrongCat(void) {
  std::cout << this->type << " destructor called" << std::endl;
}

void WrongCat::makeSound(void) { std::cout << "Meow!" << std::endl; }
