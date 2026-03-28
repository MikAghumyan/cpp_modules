#include "Zombie.hpp"
Zombie *zombieHorde(int N, std::string name);

int main(void)
{
    int n = 10;
    Zombie *zombies = zombieHorde(n, "Brrro");

    for (int i = 0; i < n; ++i)
        zombies[i].announce();
    delete[] zombies;
    return (0);
}