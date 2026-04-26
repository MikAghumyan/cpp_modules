#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char *Intern::UnknownFormException::what() const throw()
{
    return "Unknown form type.";
}

const Intern::FormType Intern::m_table[3] =
    {{"shrubbery creation", &Intern::createShrubberyCreationForm},
     {"robotomy request", &Intern::createRobotomyRequestForm},
     {"presidential pardon", &Intern::createPresidentialPardonForm}};

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == m_table[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return m_table[i].createFunc(target);
        }
    }
    throw UnknownFormException();
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}