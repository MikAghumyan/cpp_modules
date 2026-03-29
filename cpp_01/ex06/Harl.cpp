#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void (Harl::*const Harl::funcPtrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
    int i = 0;
    while (i < 4 && level != levels[i])
        i++;

    switch (i)
    {
    case 0:
        (this->*funcPtrs[0])();
        // fallthrough
    case 1:
        (this->*funcPtrs[1])();
        // fallthrough
    case 2:
        (this->*funcPtrs[2])();
        // fallthrough
    case 3:
        (this->*funcPtrs[3])();
        break;
    default:
        std::cout << "[ INVALID LEVEL ]" << std::endl;
    }
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup"
              << " burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon"
              << " in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years, whereas you started working here just last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
