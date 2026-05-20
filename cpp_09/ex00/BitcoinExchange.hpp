#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange &other);

    void loadData(const char *filename);
    float getExchangeRate(const std::string &date) const;
    void processInput(const char *inputFile);

private:
    std::map<std::string, float> _exchangeRates;

    bool _isValidDate(const std::string &date) const;
};
