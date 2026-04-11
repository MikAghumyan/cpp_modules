#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << this->type << " created" << std::endl;
}

Dog::Dog(const Dog &other)
{
    this->brain = new Brain(*other.brain);
    *this = other;
    std::cout << this->type << " copied" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << this->type << " destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << this->type << " assigned" << std::endl;
    return (*this);
}

Brain *Dog::getBrain() const
{
    return this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}