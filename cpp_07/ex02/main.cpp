#include "Array.hpp"
#include <iostream>

void print(int &n)
{
    std::cout << n << std::endl;
}

int main(void)
{
    Array<int> arr1(5);
    try
    {
        std::cout << arr1[5];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    arr1[4] = 42;
    Array<int> arr2 = arr1;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << "\n";
    return 0;
}