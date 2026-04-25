#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    ShrubberyCreationForm shrubberyForm(names[0]);
    RobotomyRequestForm robotomyForm(names[1]);
    PresidentialPardonForm pardonForm(names[2]);
    AForm *forms[3] = {&shrubberyForm, &robotomyForm, &pardonForm};
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
    return (0);
}