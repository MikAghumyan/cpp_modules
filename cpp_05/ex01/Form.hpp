#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
public:
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    Form();
    Form(const std::string &name, const int signGrade, const int executeGrade);
    Form(const Form &other);
    ~Form();

    Form &operator=(const Form &other);

    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);

private:
    const std::string m_name;
    bool m_signed;
    const int m_signGrade;
    const int m_executeGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif