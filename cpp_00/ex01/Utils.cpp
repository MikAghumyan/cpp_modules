#include "Utils.hpp"

std::string trim(std::string const &str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

std::string truncate(std::string const &str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return str;
}