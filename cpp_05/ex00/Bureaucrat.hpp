#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
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

    Bureaucrat();
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &other);

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

private:
    const std::string m_name;
    int m_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif