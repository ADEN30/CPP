#include "HumanB.hpp"
HumanB::HumanB(std::string name) {
  this->name = name;
  this->arm = NULL;
  std::cout << "HumanB constructor is called." << std::endl;
}

HumanB::~HumanB() { std::cout << "HumanB destructor is called." << std::endl; }

void HumanB::setWeapon(Weapon &arm) { this->arm = &arm; }

void HumanB::attack() {
  std::cout << this->name << " attack with their ";
  if (this->arm != NULL)
    std::cout << this->arm->getType() << std::endl;
  else
    std::cout << "hands" << std::endl;

}
