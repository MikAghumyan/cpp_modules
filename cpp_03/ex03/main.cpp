#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing DiamondTrap ---" << std::endl;
    DiamondTrap d("Dave");

    d.whoAmI();
    d.attack("Target"); // should use ScavTrap's attack
    d.takeDamage(10);
    d.beRepaired(5);
    d.guardGate();
    d.highFivesGuys();

    return 0;
}