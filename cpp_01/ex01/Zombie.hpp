#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
public:
    Zombie();
    Zombie(std::string _name);
    ~Zombie();

    void announce(void) const;
    void set_name(std::string _name);

private:
    std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif