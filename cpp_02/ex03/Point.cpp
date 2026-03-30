#include "Point.hpp"

Point::Point() : m_x(), m_y() {}

Point::Point(float const x, float const y) : m_x(x), m_y(y) {}

Point::Point(const Point &other) : m_x(other.m_x), m_y(other.m_y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Fixed Point::getX() const { return m_x; }

Fixed Point::getY() const { return m_y; }
