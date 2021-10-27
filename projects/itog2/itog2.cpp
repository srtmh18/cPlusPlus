#include <iostream>
#include "const.h"

double userValue()
{
    std::cout << "Enter a height of building: ";
    double x;
    std::cin >> x;
    return x;
}

double dropFunc(int t, double h)
{
    double r;
    double f;
    f = (grav * pow(t, 2)) / 2;
    r = h - f;
    if (r > 0)
        std::cout << "At " << t << " seconds, the ball is at height " << r << " meters." << '\n';
    else
        std::cout << "At " << t << " seconds, the ball is on the ground." << '\n';
    return 0;
}

int main()
{
    double h = userValue();
    dropFunc(0, h);
    dropFunc(1, h);
    dropFunc(2, h);
    dropFunc(3, h);
    dropFunc(4, h);
    dropFunc(5, h);
    return 0;
}