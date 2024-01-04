#ifndef TRAPCLAP
#define TRAPCLAP
#include <string>
class ClapTrap {
private:
  std::string name;
 unsigned int hitpoints;
 unsigned int energy;
 unsigned  int attackdamage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &rh);
  ClapTrap &operator=(const ClapTrap &rh);
  ~ClapTrap(void);
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
