#include "Zombie.hpp"

int main(void) {
  Zombie *zb;

  zb = newZombie("patrick");
  zb->announce();

  randomChump("Baptiste");
  delete zb;
  return (0);
}
