#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    virtual ~Cat();

    Cat &operator=(const Cat &other);

    Brain *getBrain() const;
    virtual void makeSound() const;

private:
    Brain *brain;
};

#endif