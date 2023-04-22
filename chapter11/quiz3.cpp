//Write your own function to swap the value of two integer variables

#include <iostream>

void swapIntegers(int &a, int &b)
{
	int temp{ a };
	a = b;
	b = temp;
}

void quiz3()
{
	int a{ 0 };
	int b{ 1 };
	
	std::cout << "Before swapping: \n";
	std::cout << "a: " << a << ", b: " << b << '\n';

	swapIntegers(a, b);

	std::cout << "After swapping: \n";
	std::cout << "a: " << a << ", b: " << b << '\n';
}