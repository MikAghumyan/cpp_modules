#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed.";
}

AForm::AForm() : m_name("Default"), m_signed(false), m_signGrade(150), m_executeGrade(150)
{
}

AForm::AForm(const std::string &name, const int signGrade, const int executeGrade)
    : m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
    if (m_signGrade < 1 || m_executeGrade < 1)
        throw GradeTooHighException();
    else if (m_signGrade > 150 || m_executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : m_name(other.m_name), m_signed(other.m_signed),
      m_signGrade(other.m_signGrade), m_executeGrade(other.m_executeGrade)
{
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        m_signed = other.m_signed;
    }
    return (*this);
}

std::string AForm::getName() const { return m_name; }

bool AForm::getSigned() const { return m_signed; }

int AForm::getSignGrade() const { return m_signGrade; }

int AForm::getExecuteGrade() const { return m_executeGrade; }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= m_signGrade)
        m_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!m_signed)
        throw FormNotSignedException();
    else if (executor.getGrade() > m_executeGrade)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    return os
           << form.getName() << (form.getSigned() ? ", already signed" : ", isn't signed")
           << ", required to sign " << form.getSignGrade()
           << ", required to execute " << form.getExecuteGrade() << ".";
}