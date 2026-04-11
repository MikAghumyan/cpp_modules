#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << this->type << " created" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << this->type << " copied" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << this->type << " destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
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

Brain *Cat::getBrain() const
{
    return this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}