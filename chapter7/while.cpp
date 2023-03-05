#include <iostream>

void printLetters() {
	char letter{ 'a' };
	while (letter <= 'z') {
		std::cout << letter << " - " << static_cast<int>(letter) << '\n';
		++letter;
	}
}

void printNumbers1() {
	int x{ 5 };
	while (x > 0) {
		int y{ x };
		while (y > 0) {
			std::cout << y << ' ';
			--y;
		}
		std::cout << '\n';
		--x;
	}
}

void printNumbers2() {
	int x{ 1 };
	while (x <= 5) {
		int y{ 5 };
		while (y > 0) {
			if (y <= x) std::cout << y << ' ';
			else std::cout << "  ";
			--y;
		}
		std::cout << '\n';
		++x;
	}
}