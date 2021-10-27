#include <iostream>

int readnumber()
{
    std::cout << "Enter one integer: ";
    int value;
    std::cin >> value;
    return value;
}

int writeAnswer(int x, int y)
{
    return x + y;
}