#include "Fixed.hpp"

Fixed::Fixed() : m_value(0) {}

Fixed::Fixed(const int value) : m_value(value << m_fractBits) {}

Fixed::Fixed(const float value)
    : m_value(static_cast<int>(roundf(value * (1 << m_fractBits)))) {}

Fixed::Fixed(const Fixed &other) : m_value(other.m_value) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->m_value = other.m_value;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const { return (this->m_value > other.m_value); }
bool Fixed::operator>=(const Fixed &other) const { return (this->m_value >= other.m_value); }
bool Fixed::operator<(const Fixed &other) const { return (this->m_value < other.m_value); }
bool Fixed::operator<=(const Fixed &other) const { return (this->m_value <= other.m_value); }
bool Fixed::operator==(const Fixed &other) const { return (this->m_value == other.m_value); }
bool Fixed::operator!=(const Fixed &other) const { return (this->m_value != other.m_value); }
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.m_value = (this->m_value + other.m_value);
    return (result);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.m_value = (this->m_value - other.m_value);
    return (result);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.m_value = (this->m_value * other.m_value) >> m_fractBits;
    return (result);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.m_value = (this->m_value / other.m_value) << m_fractBits;
    return (result);
}

Fixed &Fixed::operator++()
{
    ++m_value;
    return (*this);
}
Fixed &Fixed::operator--()
{
    --m_value;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    ++m_value;
    return (result);
}
Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    --m_value;
    return (result);
}

int Fixed::getRawBits(void) const { return this->m_value; }

void Fixed::setRawBits(int const raw) { this->m_value = raw; }

int Fixed::toInt(void) const { return (m_value >> m_fractBits); }

float Fixed::toFloat(void) const { return (static_cast<float>(m_value) / (1 << m_fractBits)); }

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2) { return (nb1 < nb2 ? nb1 : nb2); }
const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2) { return (nb1 < nb2 ? nb1 : nb2); }
Fixed &Fixed::max(Fixed &nb1, Fixed &nb2) { return (nb1 > nb2 ? nb1 : nb2); }
const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2) { return (nb1 > nb2 ? nb1 : nb2); }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}