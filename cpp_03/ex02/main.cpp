#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing FragTrap ---" << std::endl;
    FragTrap f("Frank");

    f.attack("Target");
    f.takeDamage(30);
    f.beRepaired(20);
    f.highFivesGuys();

    return 0;
}