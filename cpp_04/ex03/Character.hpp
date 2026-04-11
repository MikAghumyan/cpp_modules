#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    virtual ~Character();

    Character &operator=(const Character &other);
    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);

private:
    static const int inventorySize = 4;
    std::string m_name;
    AMateria *m_inventory[inventorySize];
};

#endif