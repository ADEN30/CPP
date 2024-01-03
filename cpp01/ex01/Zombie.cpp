#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
  this->name = name;
  std::cout << "Zombie " << this->name << "is create !" << std::endl;
}

Zombie::~Zombie(void) {
  std::cout << "Zombie " << this->name << "is delete !" << std::endl;
}

void Zombie::announce() {
  std::cout << "My name is " << this->name << std::endl;
}

void Zombie::setname(std::string name) { this->name = name; }
