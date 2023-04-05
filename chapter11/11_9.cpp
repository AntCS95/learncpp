#include <iostream>
#include <iterator>

int* findValue(int* begin, int* end, int value)
{
    int* ptr{};
    for (ptr = begin; ptr != end; ++ptr)
    {
        if (*ptr == value) break;
    }
    return ptr;
}

void printFindValue()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 40) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }
}