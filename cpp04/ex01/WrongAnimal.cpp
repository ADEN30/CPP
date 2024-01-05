
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
  this->type = "WrongAnimal";
  std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
  this->type = type;
  std::cout << "WrongAnimal " << this->type << " constructor called"
            << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  *this = src;
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  this->type = rhs.type;
  std::cout << "WrongAnimal assignment operator called" << std::endl;
  return *this;
}

void WrongAnimal::makeSound(void) {
  std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string WrongAnimal::gettype(void) { return this->type; }
