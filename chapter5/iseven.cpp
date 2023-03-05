#include <iostream>

int getNumber() {
	int x{};
	std::cout << "Enter number: ";
	std::cin >> x;
	return x;
}

void isEven() {
	int x{ getNumber() };
	std::cout << "Number " << x << " is ";
	if (x % 2 == 0) std::cout << "even";
	else std::cout << "odd";
}

