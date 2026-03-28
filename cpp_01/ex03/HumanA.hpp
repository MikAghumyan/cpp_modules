#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string &name, Weapon &wp);
    ~HumanA();

    void attack();

private:
    std::string m_name;
    Weapon &m_weapon;
};

#endif