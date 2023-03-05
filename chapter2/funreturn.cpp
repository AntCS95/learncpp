#include <iostream>

int returnFive() {
	5;
	return 5;
}

void undefined() {
	int x{ returnFive() };
	std::cout << x;
}