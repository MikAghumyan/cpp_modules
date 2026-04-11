#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << this->type << " created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    std::cout << this->type << " copied" << std::endl;
}

Cat::~Cat()
{
    std::cout << this->type << " destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << this->type << " assigned" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}