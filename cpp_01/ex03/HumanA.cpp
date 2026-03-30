#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &wp) : m_name(name), m_weapon(wp)
{
    std::cout << m_name << "was born" << std::endl;
}

HumanA::~HumanA() { std::cout << m_name << "was died" << std::endl; }

void HumanA::attack()
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}