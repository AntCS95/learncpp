/*
a) Write a class named Fraction that has an integer numerator and denominator
member. Write a print() function that prints out the fraction.

b) Add overloaded multiplication operators to handle multiplication between a
Fraction and integer, and between two Fractions. Use the friend function method.
*/

#include "Fraction.h"

void test14_2()
{
    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    f6.print();
}