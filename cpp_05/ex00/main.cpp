#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("Vazgen", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat b2("Vahan", 149);
    Bureaucrat b3("Vigen", 2);
    b2.incrementGrade();
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    try
    {
        b2.decrementGrade();
        std::cout << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    b3.incrementGrade();
    std::cout << b3 << std::endl;
    try
    {
        b3.incrementGrade();
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}