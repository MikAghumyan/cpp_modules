#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(target + "_PresidentialPardonForm", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), m_target(other.m_target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}