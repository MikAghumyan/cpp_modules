#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << this->type << " created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other;
    std::cout << this->type << " copied" << std::endl;
}

Dog::~Dog()
{
    std::cout << this->type << " destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << this->type << " assigned" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}