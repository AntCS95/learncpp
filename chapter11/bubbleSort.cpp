#include <iostream>
#include <iterator>
#include <utility>

//constexpr int arraySize{ 9 };
int array[]{ 6,3,2,9,7,1,5,4,8 };
constexpr int arraySize{ std::size(array)};



void bubbleSort(int array[arraySize])
{
	for (int subArraySize{ arraySize }, count{ 1 }; subArraySize > 1; --subArraySize, ++count)
	{
		bool isSorted{true};
		for (int index{ 0 }; index < (subArraySize-1); ++index)
		{
			if (array[index] > array[index + 1])
			{
				std::swap(array[index], array[index + 1]);
				isSorted = false;
			}
		}
		if (isSorted)
		{
			std::cout << "Early terminatin on iteration " << count << std::endl;
			break;
		}
	}
}

void printBubbleSort()
{
	void printArray(const int array[], const int length);

	printArray(array, arraySize);
	bubbleSort(array);
	printArray(array, arraySize);
}