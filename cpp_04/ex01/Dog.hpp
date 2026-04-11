#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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