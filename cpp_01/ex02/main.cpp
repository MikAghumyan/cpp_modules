#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "address: &str" << &str << std::endl
              << "address: stringPTR" << stringPTR << std::endl
              << "address: &stringREF" << &stringREF << std::endl
              << "value str: " << str << std::endl
              << "value str: " << *stringPTR << std::endl
              << "value str: " << &stringREF << std::endl;
    return (0);
}