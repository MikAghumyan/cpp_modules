#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &nb1, Fixed &nb2);
    static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
    static Fixed &max(Fixed &nb1, Fixed &nb2);
    static const Fixed &max(const Fixed &nb1, const Fixed &nb2);

private:
    int m_value;
    static const int m_fractBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif