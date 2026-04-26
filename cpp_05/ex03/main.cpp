#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3];
    Intern intern;
    for (int i = 0; i < 3; i++)
    {
        try
        {
            forms[i] = intern.makeForm(names[i], "Target");
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return (1);
        }
        try
        {
            forms[i] = intern.makeForm("unknown form", "Target");
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    Bureaucrat b1("Vazgen", 150);
    Bureaucrat b2("Vahan", 72);
    Bureaucrat b3("Vigen", 25);
    Bureaucrat *bureaucrats[3] = {&b1, &b2, &b3};
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            try
            {
                bureaucrats[j]->signForm(*forms[i]);
                bureaucrats[j]->executeForm(*forms[i]);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }

    for (int i = 0; i < 3; i++)
        delete forms[i];
    return (0);
}