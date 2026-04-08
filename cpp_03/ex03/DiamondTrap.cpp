#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap("_clap_name"), FragTrap("_clap_name")
{
    this->m_hitPoints = 100;
    this->m_energyPoints = 50;
    this->m_attackDamage = 30;
    std::cout << "DiamondTrap " << this->m_name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), m_name(name)
{
    this->m_hitPoints = 100;
    this->m_energyPoints = 50;
    this->m_attackDamage = 30;
    std::cout << "DiamondTrap " << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), m_name(other.m_name)
{
    std::cout << "DiamondTrap copy constructor called for " << other.m_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->m_name << " destructed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->m_name = other.m_name;
        std::cout << "DiamondTrap assignment operator called for " << other.m_name << std::endl;
    }
    return *this;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "I am " << this->m_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}