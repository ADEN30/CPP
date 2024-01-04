#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
  this->name = "Default";
  this->hitpoints = 10;
  this->energy = 10;
  this->attackdamage = 0;
  std::cout << "Default ClapTrap is created.\n";
}

ClapTrap::ClapTrap(std::string name) {
  this->name = name;
  this->hitpoints = 10;
  this->energy = 10;
  this->attackdamage = 0;
  std::cout << "ClapTrap " << name << "is created.\n";
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name << "is deleted.\n";
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
  }
else if (this->hitpoints == 0)
{
	std::cout << "ClapTrap " << this->name << "is dead, can't to attack" << std::endl;
}
 else {
    std::cout << "ClapTrap " << this->name << " attack " << target
              << ", causing " << this->attackdamage << " damages\n";
    this->energy -= 1;
  }
}
void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitpoints <= amount)
  {
	  this->hipoints = 0;
      std::cout << "ClapTrap " << this->name << " is dead !\n";
  }
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
  } 
else if (this->hitpoints == 0)
{
	std::cout << "ClapTrap " << this->name << "is dead, can't to repaire" << std::endl;
}
else {
    std::cout << "ClapTrap " << this->name << " is reparing\n";
    this->energy -= 1;
    this->hitpoints += amount;
  }
}
