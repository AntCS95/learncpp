#include <iostream>

void multiply() {
	//request number from user
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	//double and triple
	std::cout << "Double " << x << " is: " << x * 2 << "\n";
	std::cout << "Triple " << x << " is: " << x * 3 << "\n";
	return;
}