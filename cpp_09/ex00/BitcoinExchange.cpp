#include "BitcoinExchange.hpp"
#include <cstdlib>

static bool isNumeric(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

void BitcoinExchange::loadData(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + std::string(filename));

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        char extra;
        float rate;
        if (!(std::getline(iss, date, ',') && iss >> rate &&
              !(iss >> extra) && _isValidDate(date) && rate >= 0))
            throw std::runtime_error("Invalid data format: " + line);
        _exchangeRates[date] = rate;
    }
}

void BitcoinExchange::processInput(const char *inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + std::string(inputFile));

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        char extra;
        float amount;
        if (!(std::getline(iss, date, '|') && iss >> amount &&
              !(iss >> extra) && amount >= 0))
        {
            std::cerr << "Error: Invalid input format => " << line << std::endl;
            continue;
        }
        if (date[date.size() - 1] == ' ')
            date = date.substr(0, date.size() - 1);
        if (!_isValidDate(date))
        {
            std::cerr << "Error: Invalid date format => " << date << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        if (rate < 0)
        {
            std::cerr << "Error: No exchange rate available for date => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << amount << " = " << (amount * rate) << std::endl;
    }
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.end())
        return -1;
    if (it->first == date)
        return it->second;
    if (it == _exchangeRates.begin())
        return -1;

    --it;
    return it->second;
}
bool BitcoinExchange::_isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (!isNumeric(date.substr(0, 4)) || !isNumeric(date.substr(5, 2)) || !isNumeric(date.substr(8, 2)))
        return false;

    // Basic bounds
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Days in each month (index 1 = Jan, 2 = Feb, etc.)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leap year calculation for February
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[2] = 29;

    // Check if day exceeds the maximum allowed for that month
    if (day > daysInMonth[month])
        return false;

    return true;
}
