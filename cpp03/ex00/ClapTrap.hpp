#ifndef TRAPCLAP
#define TRAPCLAP
#include <string>
class ClapTrap {
private:
  std::string name;
  int hitpoints = 10;
  int energy = 10;
  int attackdamage = 0;

public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &rh);
  ClapTrap &operator=(const ClapTrap &rh);
  ~ClapTrap(void);
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
