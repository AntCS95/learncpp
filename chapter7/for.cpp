#include <iostream>

void printEven020() {
	for (int x{ 0 }; x <= 20; x+=2) {
		std::cout << x << ' ';
	}
}

int sumTo(int value) {
	int sum{ 0 };
	for (int count{ 1 }; count <= value; ++count) {
		sum += count;
	}
	return sum;
}