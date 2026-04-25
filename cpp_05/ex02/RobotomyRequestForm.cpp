#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(target + "_RobotomyRequestForm", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), m_target(other.m_target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "* drilling noises *" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    if (std::rand() % 2)
        std::cout << m_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << m_target << " robotomy failed." << std::endl;
}