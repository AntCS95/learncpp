#include <iostream>
#include <string>

void nameAgeSum() {
	//Enter name
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	//Enter age
	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;
	//Print
	std::cout << "Your age + length of name is: " << age + name.length();

}