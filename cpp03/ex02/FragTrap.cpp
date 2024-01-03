#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->name = name;
  this->hitpoints = 100;
  this->energy = 100;
  this->attackdamage = 30;
  std::cout << "FragTrap  " << name << " is created.\n";
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->name << " is delete.\n";
}

void FragTrap::highFiveGuys(void) {
  std::cout << "FragTrap " << this->name
            << ": You want a high five?\nHere you go." << std::endl;
}
