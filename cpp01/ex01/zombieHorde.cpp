#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  int i;
  Zombie *tab = new Zombie[N];

  std::cout << "alocated" << std::endl;
  std::string *n = new std::string[N];
  i = 0;
  while (i < N) {
    n[i++] = name;
  }
  i = 0;
  while (i < N) {
    tab[i].setname(n[i]);
    i++;
  }
  delete[] n;
  return (tab);
}
