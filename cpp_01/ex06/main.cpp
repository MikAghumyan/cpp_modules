#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harlObj;
    if (argc != 2)
        std::cout << "Invalid usage\n";
    else
        harlObj.complain(std::string(argv[1]));
    return (0);
}