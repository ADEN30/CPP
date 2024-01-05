#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &copy);
  ~FragTrap();
  FragTrap &operator=(const FragTrap &src);
  void highFiveGuys(void);
};

#endif // !SCAVTRAP
