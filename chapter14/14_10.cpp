#include "MyString.h"

#include <iostream>

void test14_10()
{
	MyString s{ "Hello, world!" };
	std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters
}