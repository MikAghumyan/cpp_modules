#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->m_hitPoints = 100;
    this->m_energyPoints = 50;
    this->m_attackDamage = 20;
    std::cout << "ScavTrap " << this->m_name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->m_hitPoints = 100;
    this->m_energyPoints = 50;
    this->m_attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for " << other.m_name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->m_name << " destructed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap assignment operator called for " << other.m_name << std::endl;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->m_name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage!" << std::endl;
        this->m_energyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->m_name << " cannot attack"
                  << (this->m_hitPoints <= 0 ? " because it has no hit points left!" : " because it is out of energy!")
                  << std::endl;
}
