#include <iostream>

constexpr int array[]{ 4,6,7,3,8,2,1,9,5 };

bool checkInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

int getIndex()
{
	int index{};
	while (true) {
		std::cout << "Enter index between 1 and 9: ";
		std::cin >> index;
		if (checkInput() && index > 0 && index < 10) break;
		std::cout << "Invalid index\n";
	}
	std::cout << "Valid index\n";
	return index;
}

void printArray(const int array[], const int length)
{
	std::cout << "{ ";
	for (int i{ 0 }; i < length; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '}' << std::endl;
}

void printIndex()
{
	int index{ getIndex() };
	std::cout << "For array ";
	printArray(array, std::size(array));
	std::cout << '\n';
	std::cout << "Value at index " << index << " is: " << array[index-1];
}