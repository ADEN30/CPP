#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) {
  this->name = name;
  std::cout << "ClapTrap " << name << " is created.\n";
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name << " is deleted.\n";
}

ClapTrap::ClapTrap(const ClapTrap &rhs) {
  *this = rhs;
  std::cout << "ClapTrap copy constructor called" << std::endl;
  return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  this->name = rhs.name;
  this->hitpoints = rhs.hitpoints;
  this->energy = rhs.energy;
  this->attackdamage = rhs.attackdamage;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (this->energy <= 0) {
    std::cout << "ClapTrap " << this->name
              << " doesn't have energy to attack.\n";
  } else {
    std::cout << "ClapTrap " << this->name << " attack " << target
              << ", causing " << this->attackdamage << " damages\n";
    this->energy -= 1;
  }
}
void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitpoints <= amount)
    std::cout << "ClapTrap " << this->name << " is dead !\n";
  else {
    std::cout << "ClapTrap " << this->name << " take " << amount
              << " damage !\n";
    this->hitpoints -= amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energy <= 0) {
    std::cout << "ClapTrap " << this->name
              << " doesn't have energy to repaired.\n";
  } else {
    std::cout << "ClapTrap " << this->name << " is reparing\n";
    this->energy -= 1;
    this->hitpoints += amount;
  }
}
