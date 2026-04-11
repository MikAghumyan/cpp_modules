#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : m_name("Unknown")
{
    for (int i = 0; i < inventorySize; ++i)
        m_inventory[i] = NULL;
}
Character::Character(const std::string &name) : m_name(name)
{
    for (int i = 0; i < inventorySize; ++i)
        m_inventory[i] = NULL;
}
Character::Character(const Character &other) : m_name(other.m_name)
{
    for (int i = 0; i < inventorySize; ++i)
        m_inventory[i] = other.m_inventory ? other.m_inventory[i]->clone() : NULL;
}
Character::~Character()
{
    for (int i = 0; i < inventorySize; ++i)
    {
        if (m_inventory[i])
            delete m_inventory[i];
        m_inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        for (int i = 0; i < inventorySize; ++i)
        {
            if (m_inventory[i])
                delete m_inventory[i];
            m_inventory[i] = other.m_inventory ? other.m_inventory[i]->clone() : NULL;
        }
    }
    return (*this);
}

std::string const &Character::getName() const { return (m_name); }

void Character::equip(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < inventorySize; ++i)
        {
            if (m_inventory[i] == m)
                return;
            if (!m_inventory[i])
            {
                m_inventory[i] = m;
                return;
            }
        }
    }
}
void Character::unequip(int idx)
{
    if (idx > 0 && idx < 4 && m_inventory[idx])
        m_inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        return;
    if (m_inventory[idx] == NULL)
        return;
    m_inventory[idx]->use(target);
}