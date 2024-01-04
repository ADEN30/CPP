#include "ClapTrap.hpp"

int main(void) {
  ClapTrap clap("Ashe");
  ClapTrap draven("Draven");

  clap.attack("Draven");
  draven.takeDamage(6);
  draven.takeDamage(13);
  for (int i = 0; i < 10; i++)
    clap.attack("Draven");
  draven.beRepaired(1);
  draven.takeDamage(4);
  draven.takeDamage(1);
  return (0);
}
