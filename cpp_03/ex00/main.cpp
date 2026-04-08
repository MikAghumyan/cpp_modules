#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing ClapTrap ---" << std::endl;
    ClapTrap a("Alice");
    ClapTrap b("Bob");

    a.attack("Bob");
    b.takeDamage(0);
    b.beRepaired(5);

    return 0;
}