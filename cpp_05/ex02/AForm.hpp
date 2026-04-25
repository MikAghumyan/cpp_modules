#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
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
    class FormNotSignedException : public std::exception
    {
        const char *what() const throw();
    };

    AForm();
    AForm(const std::string &name, const int signGrade, const int executeGrade);
    AForm(const AForm &other);
    virtual ~AForm();

    AForm &operator=(const AForm &other);

    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

private:
    const std::string m_name;
    bool m_signed;
    const int m_signGrade;
    const int m_executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif