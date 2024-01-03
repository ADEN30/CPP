#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->name = name;
  std::cout << "Call constructeur " << this->name << std::endl;
}

Zombie::~Zombie() {
  std::cout << "Call destructeur " << this->name << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
