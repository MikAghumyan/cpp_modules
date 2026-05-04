#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        (void)other;
    }
    return (*this);
}

static void printImpossibleConversions()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

template <typename T>
static void printConversion(const T &value)
{
    std::ios::fmtflags flags = std::cout.flags();

    if (value >= 0 && value < 128 && std::isprint(static_cast<unsigned char>(value)))
        std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
    else if (value >= 0 && value < 128)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (value == static_cast<long long>(value))
        std::cout << std::fixed << std::setprecision(1);

    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    if (value >= -std::numeric_limits<double>::max() && value <= std::numeric_limits<double>::max())
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;

    std::cout.flags(flags);
}

static ScalarConverter::LiteralType getLiteralType(const std::string &literalStr)
{
    if (literalStr.empty())
        return (ScalarConverter::UNDEFINED_LITERAL);
    if (literalStr == "-inff" || literalStr == "+inff" || literalStr == "nanf")
        return (ScalarConverter::PSEUDO_LITERAL);
    if (literalStr == "-inf" || literalStr == "+inf" || literalStr == "nan")
        return (ScalarConverter::PSEUDO_LITERAL);
    if (literalStr.length() == 3 && literalStr[0] == '\'' && literalStr[literalStr.size() - 1] == '\'')
        return (ScalarConverter::CHAR_LITERAL);

    std::string trimmedStr = (literalStr[0] == '+' || literalStr[0] == '-')
                                 ? literalStr.substr(1)
                                 : literalStr;
    if (trimmedStr.empty())
        return (ScalarConverter::UNDEFINED_LITERAL);
    if (trimmedStr.find('.') != std::string::npos)
    {
        if (trimmedStr[trimmedStr.size() - 1] == 'f' && literalStr.find('f') == literalStr.size() - 1)
            trimmedStr = trimmedStr.substr(0, trimmedStr.size() - 1);
        if (trimmedStr.empty())
            return (ScalarConverter::UNDEFINED_LITERAL);
        std::size_t dotPos = trimmedStr.find('.');

        if ((dotPos == 0 || dotPos == trimmedStr.size() - 1 ||
             trimmedStr.substr(0, dotPos).find_first_not_of("0123456789") != std::string::npos ||
             trimmedStr.substr(dotPos + 1).find_first_not_of("0123456789") != std::string::npos))
            return (ScalarConverter::UNDEFINED_LITERAL);
        if (literalStr[literalStr.size() - 1] == 'f')
            return (ScalarConverter::FLOAT_LITERAL);
        return (ScalarConverter::DOUBLE_LITERAL);
    }
    if (trimmedStr.find_first_not_of("0123456789") == std::string::npos)
        return (ScalarConverter::INT_LITERAL);
    return (ScalarConverter::UNDEFINED_LITERAL);
}

void ScalarConverter::convert(const std::string &literalStr)
{
    LiteralType type = getLiteralType(literalStr);
    switch (type)
    {
    case CHAR_LITERAL:
        printConversion(static_cast<char>(literalStr[1]));
        break;
    case INT_LITERAL:
    {
        char *end;
        long value = std::strtol(literalStr.c_str(), &end, 10);
        if (*end != '\0' || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            printImpossibleConversions();
        else
            printConversion(value);
        break;
    }
    case FLOAT_LITERAL:
    {
        std::string core = literalStr.substr(0, literalStr.size() - 1);
        char *end;
        double value = std::strtod(core.c_str(), &end);
        if (*end != '\0')
            printImpossibleConversions();
        else
            printConversion(value);
        break;
    }
    case DOUBLE_LITERAL:
    {
        char *end;
        double value = std::strtod(literalStr.c_str(), &end);
        if (*end != '\0')
            printImpossibleConversions();
        else
            printConversion(value);
        break;
    }
    case PSEUDO_LITERAL:
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literalStr == "nan" || literalStr == "-inf" || literalStr == "+inf")
        {
            std::cout << "float: " << (literalStr + "f") << std::endl;
            std::cout << "double: " << literalStr << std::endl;
        }
        else
        {
            std::cout << "float: " << literalStr << std::endl;
            std::cout << "double: " << literalStr.substr(0, literalStr.size() - 1) << std::endl;
        }
        break;
    case UNDEFINED_LITERAL:
        printImpossibleConversions();
        break;
    }
}
