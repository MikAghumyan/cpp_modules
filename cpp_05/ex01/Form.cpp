#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

Form::Form() : m_name("Default"), m_signed(false), m_signGrade(150), m_executeGrade(150)
{
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
    : m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
    if (m_signGrade < 1 || m_executeGrade < 1)
        throw GradeTooHighException();
    else if (m_signGrade > 150 || m_executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : m_name(other.m_name), m_signed(other.m_signed),
      m_signGrade(other.m_signGrade), m_executeGrade(other.m_executeGrade)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        m_signed = other.m_signed;
    }
    return (*this);
}

std::string Form::getName() const { return m_name; }

bool Form::getSigned() const { return m_signed; }

int Form::getSignGrade() const { return m_signGrade; }

int Form::getExecuteGrade() const { return m_executeGrade; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= m_signGrade)
        m_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    return os
           << form.getName() << (form.getSigned() ? ", already signed" : ", isn't signed")
           << ", required to sign " << form.getSignGrade()
           << ", required to execute " << form.getExecuteGrade() << ".";
}