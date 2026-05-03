#include "Utils.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	srand(static_cast<unsigned>(time(0)));
	int r = rand() % 3;
	switch (r)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	default:
		return new C();
	}
}

void identify(Base* p)
{
	std::cout << "Identified Type by Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Identified Type by Refernence: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception&) {}
}
