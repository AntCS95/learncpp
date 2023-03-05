#include <iostream>

int calculate(int x, int y, char op) {

	switch (op) {
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
		case '%': return x % y;
	}

}

void execCalculate() {
	int x{}, y{};
	char op{};
	std::cout << "Enter an integer: ";
	std::cin >> x;
	std::cout << "Enter another integer: ";
	std::cin >> y;
	std::cout << "Enter an operator: ";
	std::cin >> op;
	std::cout << "Result is: " << calculate(x, y, op);
}