#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name) : m_name(name), m_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name), m_grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        m_grade = other.m_grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const { return m_name; }

int Bureaucrat::getGrade() const { return m_grade; }

void Bureaucrat::incrementGrade()
{
    m_grade--;
    if (m_grade < 1)
        throw GradeTooHighException();
}
void Bureaucrat::decrementGrade()
{
    m_grade++;
    if (m_grade > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}