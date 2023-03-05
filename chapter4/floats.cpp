#include <iomanip> // for std::setprecision()
#include <iostream>

void floatPrecision()
{
    double d{ 0.5 };
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << '\n';
}