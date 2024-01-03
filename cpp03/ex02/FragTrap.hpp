#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
  FragTrap(void);

public:
  FragTrap(std::string name);
  ~FragTrap();
  void highFiveGuys(void);
};

#endif // !SCAVTRAP
