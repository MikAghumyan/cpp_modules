#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copied" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}