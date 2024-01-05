#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Draven");
    ScavTrap scav2("Ash");
    ScavTrap scaav = scav;
    scav.attack("Ash");
    scav2.takeDamage(500);
    scav2.beRepaired(10);
    scav2.guardGate();
    return 0;
}
