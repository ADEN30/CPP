#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arm) : arm(arm) {
  this->name = name;
  std::cout << "HumanA constructor is called." << std::endl;
}

HumanA::~HumanA() { std::cout << "HumanA destructor is called." << std::endl; }

void HumanA::attack() {
  std::cout << this->name << " attack with their ";
  std::cout << this->arm.getType() << std::endl;
}
