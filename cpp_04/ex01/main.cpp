#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int numAnimals = 10;
    Animal *animals[numAnimals];

    std::cout << "--- CREATING ANIMALS ---" << std::endl;
    for (int i = 0; i < numAnimals; i++)
    {
        if (i < numAnimals / 2)
        {
            animals[i] = new Dog();
        }
        else
        {
            animals[i] = new Cat();
        }
    }

    std::cout << "\n--- DESTROYING ANIMALS ---" << std::endl;
    for (int i = 0; i < numAnimals; i++)
    {
        delete animals[i];
    }

    return 0;
}