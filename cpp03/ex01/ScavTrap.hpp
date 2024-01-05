#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &copy);
  ScavTrap &operator=(const ScavTrap &src);
  ~ScavTrap();
  void attack(const std::string &name);
  void guardGate(void);
};

#endif // !SCAVTRAP
