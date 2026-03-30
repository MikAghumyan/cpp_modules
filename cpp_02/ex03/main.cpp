#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0.f, 0.f);
    Point b(10.f, 0.f);
    Point c(0.f, 10.f);

    Point inside(1.f, 1.f);
    Point outside(10.f, 10.f);
    Point on_edge(5.f, 0.f);

    std::cout << "inside: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "outside: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "on_edge: " << (bsp(a, b, c, on_edge) ? "true" : "false") << std::endl;

    return 0;
}