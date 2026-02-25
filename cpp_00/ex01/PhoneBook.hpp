#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iomanip>
#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    unsigned int _count;
    unsigned int _oldest;

public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void search();

private:
    std::string _returnField(std::string prompt);
    bool _isNumberValid(std::string const &number);
};

#endif