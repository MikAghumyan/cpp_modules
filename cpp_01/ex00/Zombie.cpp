#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie Created" << std::endl;
}

Zombie::Zombie(std::string _name) : name(_name)
{
    std::cout << "Zombie Created" << std::endl;
};

Zombie::~Zombie()
{
    std::cout << "Zombie Died" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}