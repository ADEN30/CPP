#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>
class HumanA {
public:
  HumanA(std::string name, Weapon &arm);
  ~HumanA();
  void attack();

private:
  Weapon &arm;
  std::string name;
};

#endif
