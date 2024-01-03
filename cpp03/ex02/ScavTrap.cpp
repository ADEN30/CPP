#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->name = name;
  this->hitpoints = 100;
  this->energy = 50;
  this->attackdamage = 20;
  std::cout << "ScavTrap constructor is called !\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name << " is delete.\n";
}

void ScavTrap::attack(const std::string &target) {
  if (this->energy <= 0) {
    std::cout << "ScavTrap " << this->name
              << " doesn't have energy to attack.\n";
  } else {
    std::cout << "ScavTrap " << this->name << " attack " << target
              << ", causing " << this->attackdamage << " damages\n";
    this->energy -= 1;
  }
}

void ScavTrap::guardGate(void) {
  std::cout << "< ScavTrap > - " << this->name
            << " is now in Gate keeper mode.\n";
}
