#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(const std::string &name);
    ~HumanB();

    void setWeapon(Weapon &wp);

    void attack();

private:
    std::string m_name;
    Weapon *m_weapon;
};

#endif