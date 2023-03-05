#include <iostream>

void zeroDivision() {
	//std::cout << 5 / 0.0;
	std::cout << "Enter a divisor: ";
	double  x{};
	std::cin >> x;

	std::cout << "12 / " << x << " = " << -12 / x << '\n';
}