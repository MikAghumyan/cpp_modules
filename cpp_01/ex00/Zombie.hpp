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

private:
    std::string name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif