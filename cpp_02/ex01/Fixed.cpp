#include "Fixed.hpp"

Fixed::Fixed() : m_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : m_value(value << m_fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : m_value(static_cast<int>(roundf(value * (1 << m_fractBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : m_value(other.m_value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->m_value = other.m_value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->m_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->m_value = raw;
}

int Fixed::toInt(void) const
{
    return (m_value >> m_fractBits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(m_value) / (1 << m_fractBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}