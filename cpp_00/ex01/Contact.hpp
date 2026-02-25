#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
#include "Utils.hpp"

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    Contact(std::string firstName, std::string lastName, std::string nickname,
            std::string phoneNumber, std::string darkestSecret);
    ~Contact();

    void setFirstName(std::string firstName);
    std::string getFirstName() const;

    void setLastName(std::string lastName);
    std::string getLastName() const;

    void setNickname(std::string nickame);
    std::string getNickname() const;

    void setPhoneNumber(std::string phoneNumber);
    std::string getPhoneNumber() const;

    void setDarkestSecret(std::string darkestsecret);
    std::string getDarkestSecret() const;

    void print();

private:

};

#endif