#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing ScavTrap ---" << std::endl;
    ScavTrap s("Sam");

    s.attack("Enemy");
    s.takeDamage(20);
    s.beRepaired(10);
    s.guardGate();

    return 0;
}