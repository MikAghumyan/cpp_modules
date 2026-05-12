#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T, typename ContainerType = std::deque<T>>
class MutantStack : public std::stack<T, ContainerType>
{
public:
    typedef typename ContainerType::iterator iterator;
    typedef typename ContainerType::const_iterator const_iterator;
    typedef typename ContainerType::reverse_iterator reverse_iterator;
    typedef typename ContainerType::const_reverse_iterator const_reverse_iterator;

    MutantStack() : std::stack<T, ContainerType>() {}
    MutantStack(const MutantStack &other) : std::stack<T, ContainerType>(other) {}
    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            std::stack<T, ContainerType>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif