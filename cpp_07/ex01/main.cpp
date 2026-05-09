#include "iter.hpp"
#include <iostream>

template <typename T>
void printTemplate(T const &x)
{
    std::cout << x << std::endl;
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};
    std::cout << "Testing printTemplate on int array:" << std::endl;
    iter(array, 5, printTemplate<int>);

    std::string strArray[] = {"Hello", "42", "World"};
    std::cout << "Testing printTemplate on string array:" << std::endl;
    iter(strArray, 3, printTemplate<std::string>);

    return 0;
}