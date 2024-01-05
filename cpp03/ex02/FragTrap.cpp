#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  this->name = "Default";
  this->hitpoints = 100;
  this->energy = 100;
  this->attackdamage = 30;
  std::cout << "Default FragTrap is created.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->name = name;
  this->hitpoints = 100;
  this->energy = 100;
  this->attackdamage = 30;
  std::cout << "FragTrap  " << name << " is created.\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
  *this = copy;
  std::cout << "FragTrap constructor copy called\n";
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->name << " is delete.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
  this->name = src.name;
  this->hitpoints = src.hitpoints;
  this->energy = src.energy;
  this->attackdamage = src.attackdamage;
  std::cout << "FragTrap operator assignement.\n";
  return *this;
}

void FragTrap::highFiveGuys(void) {
  std::cout << "FragTrap " << this->name
            << ": You want a high five?\nHere you go." << std::endl;
}
