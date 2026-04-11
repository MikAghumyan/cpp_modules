#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << this->type << " created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    *this = other;
    std::cout << this->type << " copied" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << this->type << " destroyed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << this->type << " assigned" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}