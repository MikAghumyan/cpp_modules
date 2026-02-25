#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
                 std::string phoneNumber, std::string darkestSecret)
    : _firstName(firstName), _lastName(lastName), _nickname(nickname),
      _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) { _firstName = firstName; }
std::string Contact::getFirstName() const { return (_firstName); }

void Contact::setLastName(std::string lastName) { _lastName = lastName; }
std::string Contact::getLastName() const { return (_lastName); }

void Contact::setNickname(std::string nickname) { _nickname = nickname; }
std::string Contact::getNickname() const { return (_nickname); }

void Contact::setPhoneNumber(std::string phoneNumber) { _phoneNumber = phoneNumber; }
std::string Contact::getPhoneNumber() const { return (_phoneNumber); }

void Contact::setDarkestSecret(std::string darkestSecret) { _darkestSecret = darkestSecret; }
std::string Contact::getDarkestSecret() const { return (_darkestSecret); }

void Contact::print()
{
  std::cout << "First Name: " << _firstName << std::endl
            << "Last Name: " << _lastName << std::endl
            << "Nickname: " << _nickname << std::endl
            << "Phone Number: " << _phoneNumber << std::endl
            << "Darkest Secret: " << _darkestSecret << std::endl;
}