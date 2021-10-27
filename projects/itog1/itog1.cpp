#include <iostream>

#include "funkcii.h"

int main()
{
    int a = readnumber();
    int b = readnumber();
    std::cout << writeAnswer(a, b);
    return 0; 
}

