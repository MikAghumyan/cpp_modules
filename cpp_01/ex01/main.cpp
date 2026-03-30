#include "Zombie.hpp"

int main(void)
{
    int n = 10;
    Zombie *zombies = zombieHorde(n, "Brrro");

    if (zombies)
    {
        for (int i = 0; i < n; ++i)
            zombies[i].announce();
        delete[] zombies;
    }
    return (0);
}