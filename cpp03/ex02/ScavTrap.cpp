#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  this->name = "Default";
  this->hitpoints = 100;
  this->energy = 50;
  this->attackdamage = 20;
  std::cout << "Default ScavTrap constructor is called !\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->name = name;
  this->hitpoints = 100;
  this->energy = 50;
  this->attackdamage = 20;
  std::cout << "ScavTrap " << name << " constructor is called !\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
  *this = copy;
  std::cout << "ScavTrap constructor copy called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
  this->name = src.name;
  this->hitpoints = src.hitpoints;
  this->energy = src.energy;
  this->attackdamage = src.attackdamage;
  std::cout << "ScavTrap assignements called" << std::endl;
  return *this;
}
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name << " is delete.\n";
}

void ScavTrap::attack(const std::string &target) {
  if (this->hitpoints == 0) {
    std::cout << "ScavTrap " << this->name << " is dead, can't to attack"
              << std::endl;
  }
  else if (this->energy <= 0) {
    std::cout << "ScavTrap " << this->name
              << " doesn't have energy to attack.\n";
  }  else {
    std::cout << "ScavTrap " << this->name << " attack " << target
              << ", causing " << this->attackdamage << " damages\n";
    this->energy -= 1;
  }
}

void ScavTrap::guardGate(void) {
  std::cout << "< ScavTrap > - " << this->name
            << " is now in Gate keeper mode.\n";
}
