#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <stdexcept>

class Intern
{
public:
    class UnknownFormException : public std::exception
    {
        const char *what() const throw();
    };

    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);
    AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
    struct FormType
    {
        std::string name;
        AForm *(*createFunc)(const std::string &target);
    };
    static const FormType m_table[3];

    static AForm *createShrubberyCreationForm(const std::string &target);
    static AForm *createRobotomyRequestForm(const std::string &target);
    static AForm *createPresidentialPardonForm(const std::string &target);
};

#endif