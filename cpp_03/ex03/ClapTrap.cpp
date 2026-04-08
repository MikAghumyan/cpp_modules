#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : m_name(other.m_name),
      m_hitPoints(other.m_hitPoints),
      m_energyPoints(other.m_energyPoints),
      m_attackDamage(other.m_attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this == &other)
        return (*this);
    m_name = other.m_name;
    m_hitPoints = other.m_hitPoints;
    m_energyPoints = other.m_energyPoints;
    m_attackDamage = other.m_attackDamage;
    return (*this);
}

std::string ClapTrap::getName() const { return m_name; }

int ClapTrap::getAttackDamage() const { return m_attackDamage; }

void ClapTrap::attack(const std::string &target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage!" << std::endl;
        this->m_energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->m_name << " cannot attack"
                  << (this->m_hitPoints <= 0 ? " because it has no hit points left!" : " because it is out of energy!")
                  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    m_hitPoints -= amount;
    if (m_hitPoints < 0)
        m_hitPoints = 0;
    std::cout << "ClapTrap " << m_name << " takes " << amount
              << " points of damage! Remaining hit points: " << m_hitPoints
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_energyPoints > 0 && m_hitPoints > 0)
    {
        m_hitPoints += amount;
        m_energyPoints--;
        std::cout << "ClapTrap " << m_name << " is repaired by " << amount
                  << " points! Current hit points: " << m_hitPoints
                  << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << m_name
                  << " cannot be repaired due to insufficient energy or hit points."
                  << std::endl;
    }
}