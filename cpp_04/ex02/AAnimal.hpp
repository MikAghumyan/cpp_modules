#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
public:
    AAnimal();
    AAnimal(const AAnimal &other);
    virtual ~AAnimal();

    AAnimal &operator=(const AAnimal &other);

    std::string getType() const;
    virtual void makeSound() const = 0;

protected:
    std::string type;
};

#endif