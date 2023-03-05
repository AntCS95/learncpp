//1

//symbolic constants are better than literals because they avoid
//the use of "magic numbers": variables names explain themselfs

//const/constexpr variables are preferred to macros constants
//because they are are easier to debug (macros definitions)
//simply replace text with text. Moreover, it can lead to more
//errors (unwanted replacements may happen).

//2

//a) int
//b) bool
//c) constexpr double
//d) int
//e) float
//f) std::int32_t
//g) char
//h) std::int16_t

#include <iostream>
#include <cstdint>

double getInput() {
	double x{};
	std::cout << "Enter a double value: ";
	std::cin >> x;
	return x;
}

char getOperator() {
	char op{};
	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> op;
	return op;
}

double calculate(double x, double y, char symbol) {
	if (symbol == '+') return x + y;
	if (symbol == '-') return x - y;
	if (symbol == '*') return x * y;
	if (symbol == '/') return x / y;
}

void operate2numbers() {
	double x{getInput()};
	double y{ getInput() };
	double result{};
	char op{ getOperator() };

	if (op == '+' || op == '-' || op == '*' || op == '/') std::cout << calculate(x, y, op);
}



float getHeight() {
	float height{};
	std::cout << "Enter the height of the tower in meters: ";
	std::cin >> height;
	return height;
}


float calculateHeight(float seconds, float height, float gravity) {
	return height - gravity * seconds * seconds / 2;
}

void printHeight(float seconds, float height) {
	if (height > 0)
		std::cout << "At " << seconds << " seconds, the ball is at height: "
		<< height << " meters" << "\n";
	else std::cout << "At " << seconds << " seconds, the ball is on the ground." << "\n";
}



void ballDrop(){
	constexpr float gravity{ 9.8f };
	float height{getHeight()};
	float seconds{};
	//start
	seconds = 0.0f;
	printHeight(seconds, calculateHeight(seconds, height, gravity));
	//1 second
	seconds = 1.0f;
	printHeight(seconds, calculateHeight(seconds, height, gravity));
	//2 seconds
	seconds = 2.0f;
	printHeight(seconds, calculateHeight(seconds, height, gravity));
	//3 seconds
	seconds = 3.0f;
	printHeight(seconds, calculateHeight(seconds, height, gravity));
	//4 seconds
	seconds = 4.0f;
	printHeight(seconds, calculateHeight(seconds, height, gravity));
	//5 seconds
	seconds = 5.0f;
	printHeight(seconds, calculateHeight(seconds, height, gravity));
}

void texasDrivingLicense() {
	std::cout << "How old are you?\n";

	int age{};
	std::cin >> age;

	std::cout << "Allowed to drive a car in Texas [";

	if (age >= 16)
		std::cout << "x";
	else
		std::cout << " ";

	std::cout << "]\n";
}