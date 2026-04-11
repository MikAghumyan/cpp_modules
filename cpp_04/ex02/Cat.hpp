#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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