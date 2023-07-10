#include "Fraction.h"
#include "Car.h"

#include <iostream>
#include <vector>
#include <algorithm>

void test14_7a()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
}

void test14_7b()
{
	std::vector<Car> cars{
  { "Toyota", "Corolla" },
  { "Honda", "Accord" },
  { "Toyota", "Camry" },
  { "Honda", "Civic" }
	};

	std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

	for (const auto& car : cars)
		std::cout << car << '\n'; // requires an overloaded operator<<
}