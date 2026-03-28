#include "Zombie.hpp"
void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main(void)
{
    Zombie *firstZombie = newZombie("First");

    firstZombie->announce();
    randomChump("Second");
    delete firstZombie;
    firstZombie = NULL;
    return (0);
}