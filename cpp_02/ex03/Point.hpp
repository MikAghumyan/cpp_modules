#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(float const x, float const y);
    Point(const Point &other);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;

private:
    const Fixed m_x;
    const Fixed m_y;

    Point &operator=(const Point &other);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif