#include "Zombie.hpp"
#include <iostream>

int main(void) {
  Zombie *horde;
  int i;
  int size;
  std::string str;

  std::cout << "enter the number of zombie of the hord " << std::endl;
  std::cin >> size;
  std::cout << "enter the name of zombies" << std::endl;
  std::cin >> str;
  horde = zombieHorde(size, str);
  i = 0;

  while (i < size) {
    horde[i++].announce();
  }
  delete[] horde;
  return (0);
}
