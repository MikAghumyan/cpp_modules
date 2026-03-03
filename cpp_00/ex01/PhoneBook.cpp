#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
    Contact new_contact;

    new_contact.setFirstName(_returnField("First Name"));
    new_contact.setLastName(_returnField("Last Name"));
    new_contact.setNickname(_returnField("Nickname"));
    do
    {
        new_contact.setPhoneNumber(_returnField("Phone Number"));
    } while (!_isNumberValid(new_contact.getPhoneNumber()));
    new_contact.setDarkestSecret(_returnField("Darkest Secret"));
    _contacts[_oldest] = new_contact;
    _oldest = (_oldest + 1) % 8;
    if (_count < 8)
        _count++;
}

void PhoneBook::search()
{
    std::string input;
    unsigned int search_index;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << std::right;
    for (unsigned int i = 0; i < _count; ++i)
    {
        std::cout
            << "|" << std::setw(10) << i
            << "|" << std::setw(10) << truncate(_contacts[i].getFirstName())
            << "|" << std::setw(10) << truncate(_contacts[i].getLastName())
            << "|" << std::setw(10) << truncate(_contacts[i].getNickname())
            << "|" << std::endl;
    }
    std::cout << "Enter Contact index: ";
    if (!std::getline(std::cin, input))
        std::cin.clear();
    if (input.length() != 1 || !std::isdigit(input[0]) || (search_index = input[0] - '0') >= _count)
        std::cout << "Invalid Contact index" << std::endl;
    else
        _contacts[search_index].print();
}

std::string PhoneBook::_returnField(std::string prompt)
{
    std::string field;
    do
    {
        std::cout << "Enter: " << prompt << ": ";
        if (!std::getline(std::cin, field))
            std::cin.clear();
        field = trim(field);
        if (!field.empty())
            break;
        std::cout << "Wrong input" << std::endl;
    } while (true);
    return (field);
}

bool PhoneBook::_isNumberValid(std::string const &number)
{
    int i = 0;
    if (number.empty())
        return (false);
    if (number[0] == '+')
        i++;
    for (; number[i]; ++i)
        if (!std::isdigit(number[i]))
            return (false);
    return (true);
}