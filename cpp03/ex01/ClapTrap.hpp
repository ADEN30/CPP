#ifndef TRAPCLAP
#define TRAPCLAP
#include <string>
class ClapTrap {
protected:
  std::string name;
  int hitpoints = 100;
  int energy = 50;
  int attackdamage = 20;
  ClapTrap();

public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &rh);
  ClapTrap &operator=(const ClapTrap &rh);
  ~ClapTrap(void);
  virtual void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
