#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : m_name(name), m_weapon(NULL)
{
    std::cout << m_name << "was born" << std::endl;
}

HumanB::~HumanB() { std::cout << m_name << "was died" << std::endl; }

void HumanB::setWeapon(Weapon &wp) { this->m_weapon = &wp; }

void HumanB::attack()
{
    if (!m_weapon)
        std::cout << m_name << " has no weapon to attack " << std::endl;
    else
        std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}