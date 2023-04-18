#include <iostream>
#include <string>

char* getString()
{
	char* string{ new char[255] };
	std::cin.getline(string, 255, '\n');
	//std::cin >> string;
	return string;
}

void printString(char* string)
{
	for (char* str{ string }; *str != 0; ++str)
	{
		std::cout << *str;
	}
}

void quiz4()
{
	char* string{ getString() };
	printString(string);
	delete[] string;
}