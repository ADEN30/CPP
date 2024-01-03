#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
  ScavTrap(void);

public:
  ScavTrap(std::string name);
  ~ScavTrap();
  void attack(const std::string &name) override;
  void guardGate(void);
};

#endif // !SCAVTRAP
