#include "RPN.hpp"
#include <stdexcept>

int rpnEvaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::stack<int> operands;
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            operands.push(token[0] - '0');
        }
        else if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
        {
            if (operands.size() < 2)
                throw std::runtime_error("Invalid RPN expression");

            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();

            switch (token[0])
            {
            case '+':
                operands.push(a + b);
                break;
            case '-':
                operands.push(a - b);
                break;
            case '*':
                operands.push(a * b);
                break;
            case '/':
                if (!b)
                    throw std::runtime_error("Division by zero");
                operands.push(a / b);
                break;
            default:
                throw std::runtime_error("Invalid operator");
            }
        }
        else
            throw std::runtime_error("Invalid token");
    }

    if (operands.size() != 1)
        throw std::runtime_error("Invalid RPN expression");

    return operands.top();
}