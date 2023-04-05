#include <iostream>
#include <string_view>
#include <algorithm>

void printSortedNames()
{
	//number of names to input
	std::cout << "How many names would you like to enter? ";
	int numberOfNames{};
	std::cin >> numberOfNames;

	//allocate dynamic array
	auto names{ new std::string[numberOfNames] };

	//enter names
	for (int i{ 0 }; i < numberOfNames; ++i)
	{
		std::cout << "Enter name #" << (i + 1) << ": ";
		std::cin >> names[i];
	}
	std::cout << std::endl;

	//sort list
	std::sort(names, names + numberOfNames);

	//print sorted list
	std::cout << "Here is your sorted list:\n";
	for (int i{ 0 }; i < numberOfNames; ++i)
	{
		std::cout << "Name #" << i << ": " << names[i];
		std::cout << std::endl;
	}
}