#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { return (*this); }

static ScalarConverter::LiteralType getLiteralType(const std::string &literalStr)
{
    if (literalStr == "-inff" || literalStr == "+inff" || literalStr == "nanf")
        return (ScalarConverter::PSEUDO_LITERAL);
    if (literalStr == "-inf" || literalStr == "+inf" || literalStr == "nan")
        return (ScalarConverter::PSEUDO_LITERAL);
    if (literalStr.length() == 3 && literalStr.front() == '\'' && literalStr.back() == '\'')
        return (ScalarConverter::CHAR_LITERAL);
    if (literalStr.find('.') != std::string::npos)
    {
        if (literalStr.find_first_not_of("0123456789.f") != std::string::npos ||
            literalStr.find_first_of('.') != literalStr.find_last_of('.') || literalStr.find('.') == 0)
            return (ScalarConverter::UNDEFINED_LITERAL);
        if (literalStr.back() == 'f' && literalStr.find('f') == literalStr.size() - 1 &&
            (literalStr.find('.') != literalStr.size() - 2))
            return (ScalarConverter::FLOAT_LITERAL);
        else if (literalStr.find('.') != literalStr.size() - 1)
            return (ScalarConverter::DOUBLE_LITERAL);
        return (ScalarConverter::UNDEFINED_LITERAL);
    }
    if (literalStr.find_first_not_of("0123456789") == std::string::npos)
        return (ScalarConverter::INT_LITERAL);
    return (ScalarConverter::UNDEFINED_LITERAL);
}

void ScalarConverter::convert(const std::string &literalStr)
{
    if (literalStr == "-inff" || literalStr == "+inff" || literalStr == "nanf")
        ;
    if (literalStr == "-inf" || literalStr == "+inf" || literalStr == "nan")
        ;
}