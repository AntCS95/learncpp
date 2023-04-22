/*
1a) Create a short program asking the user for two integer inputs
and a mathematical operation(‘ + ’, ‘ - ‘, ‘ * ’, ‘ / ’).
Ensure the user enters a valid operation.
*/

#include <iostream>
#include <functional>

using Operator = char;

bool isValidOperator(Operator op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

template  <typename T>
T getInput();

template <>
Operator getInput()
{
	Operator input{};
	while (true)
	{
		std::cout << "Enter operator (+,-,*,/): ";
		std::cin >> input;
		if (isValidOperator(input)) {
			break;
		}
		else {
			std::cout << "Unvalid operator, please retry\n";
		}
	}
	return input;
}

template <>
int getInput()
{
	std::cout << "Enter integer: ";
	int input{};
	std::cin >> input;
	return input;
}

/*
1b) Write functions named add(), subtract(), multiply(), and divide().
These should take two integer parameters and return an integer.
*/

int add(int x, int y)
{
	return x + y;
}

int substract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

/*
1c) Create a type alias named ArithmeticFunction for a pointer to a function
that takes two integer parameters and returns an integer.
Use std::function, and include the appropriate header.
*/

using ArithmeticFunction = std::function<int(int, int)>;

/*
1d) Write a function named getArithmeticFunction() that takes an operator
character and returns the appropriate function as a function pointer.
*/

ArithmeticFunction getArithmeticFunction(Operator op)
{
	switch (op)
	{
	case '+': return add;
	case '-': return substract;
	case '*': return multiply;
	case '/': return divide;
	default: return nullptr;
	}
}

