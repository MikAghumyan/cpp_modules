#include "PhoneBook.hpp"
#include "Utils.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command(ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;
        command = trim(command);
        if (command == "ADD")
            phoneBook.add();
        else if (command == "SEARCH")
            phoneBook.search();
        else if (command == "EXIT")
            break;
    }
    return (0);
}