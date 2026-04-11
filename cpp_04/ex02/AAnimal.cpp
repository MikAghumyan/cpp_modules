#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unknown")
{
    std::cout << "AAnimal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    *this = other;
    std::cout << "AAnimal copied" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destroyed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "AAnimal assigned" << std::endl;
    return *this;
}

std::string AAnimal::getType() const
{
    return type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal sound" << std::endl;
}