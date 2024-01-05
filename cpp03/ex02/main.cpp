#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ScavTrap scav("Odin");
  scav.attack("target");
  scav.takeDamage(10);
  scav.beRepaired(10);
  scav.guardGate();

  FragTrap frag("Thor");
  frag.attack("target");
  frag.takeDamage(10);
  frag.beRepaired(10);
  frag.highFiveGuys();
  return 0;
}
