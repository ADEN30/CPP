#include "Zombie.hpp"
#include <iostream>

int main(void) {
  Zombie *horde;
  int i;
  std::string str;

  std::cout << "enter the name of zombies" << std::endl;
  std::cin >> str;
  horde = zombieHorde(5, str);
  i = 0;

  while (i < 5) {
    horde[i++].announce();
  }
  delete[] horde;
  return (0);
}
