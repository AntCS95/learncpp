#include <iostream>

/*
A factorial of an integer N (written N!) is defined as the product
(multiplication) of all the numbers between 1 and N (0! = 1).
Write a recursive function called factorial that returns the factorial
of the input. Test it with the first 7 factorials.
*/

int factorial(int x)
{
	if (x == 1) return 1;
	return x * factorial(x-1);
}

/*
Write a recursive function that takes an integer as input and returns the sum
of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15).
Print the answer for input 93427 (which is 25).
Assume the input values are positive.
*/

int sumDigits(int x)
{
	if (x / 10 == 0) return x % 10;
	return sumDigits(x / 10) + x % 10;
}

/*
3a) Write a program that asks the user to enter a positive integer,
and then uses a recursive function to print out the binary representation
for that number
*/

void printBinary(unsigned int x)
{
	if (x/2 > 0) printBinary(x / 2);
	std::cout << x % 2;
}