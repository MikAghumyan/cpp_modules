#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->m_hitPoints = 100;
    this->m_energyPoints = 100;
    this->m_attackDamage = 30;
    std::cout << "FragTrap " << this->m_name << " constructed." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->m_hitPoints = 100;
    this->m_energyPoints = 100;
    this->m_attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << other.m_name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->m_name << " destructed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap assignment operator called for " << other.m_name << std::endl;
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->m_name << " is requesting a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "FragTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage!" << std::endl;
        this->m_energyPoints--;
    }
    else
        std::cout << "FragTrap " << this->m_name << " cannot attack"
                  << (this->m_hitPoints <= 0 ? " because it has no hit points left!" : " because it is out of energy!")
                  << std::endl;
}
