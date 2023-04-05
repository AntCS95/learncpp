#include <iostream>
#include <array>

void printTemperature()
{
	constexpr int daysPerYear{ 365 };
	float temp[daysPerYear]{};
	std::cout << temp[300];
}

namespace animals
{
	enum
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		totalNumberOfAnimals,
	};
}

void printNumberOfLegs()
{
	int numberOfLegs[animals::totalNumberOfAnimals]{
		2, //chicken
		4, //dog
		4, //cat
		4, //elephant
		2, //duck
		0, //snake
	};
	std::cout << numberOfLegs[animals::elephant];
}

void printLoop()
{
	constexpr int array[]{ 4,6,7,3,8,2,1,9,5 };
	for (int i{}; i<std::size(array); i++)
	{
		std::cout << array[i] << std::endl;
	}
}

void printElement()
{
	std::cout << "test";
}

void printTest()
{

}