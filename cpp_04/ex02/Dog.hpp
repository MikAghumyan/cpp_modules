#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
    Dog();
    Dog(const Dog &other);
    virtual ~Dog();

    Dog &operator=(const Dog &other);

    Brain *getBrain() const;
    virtual void makeSound() const;

private:
    Brain *brain;
};

#endif