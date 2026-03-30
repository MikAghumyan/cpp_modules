#include "Zombie.hpp"

int main(void)
{
    Zombie *firstZombie = newZombie("First");

    firstZombie->announce();
    randomChump("Second");
    delete firstZombie;
    firstZombie = NULL;
    return (0);
}