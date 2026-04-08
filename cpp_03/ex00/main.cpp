#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alice");
    ClapTrap b("Bob");

    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(5);

    return 0;
}