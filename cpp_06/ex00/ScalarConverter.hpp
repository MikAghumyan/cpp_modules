#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
public:
    enum LiteralType
    {
        CHAR_LITERAL,
        INT_LITERAL,
        FLOAT_LITERAL,
        DOUBLE_LITERAL,
        PSEUDO_LITERAL,
        UNDEFINED_LITERAL
    };

    static void convert(const std::string &literalStr);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &other);
};

#endif