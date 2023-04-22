/*
Pretend you’re writing a game where the player can hold 3 types of items:
health potions, torches, and arrows. Create an enum to identify the different
types of items, and an std::array to store the number of each item the player
is carrying (the enumerators are used as indexes of the array).
The player should start with 2 health potions, 5 torches, and 10 arrows.
Write a function called countTotalItems() that returns how many items
the player has in total.
Have your main() function print the output of countTotalItems() as well as
the number of torches.
*/

#include<array>
#include <iostream>
#include <numeric>

enum Item
{
	potion,
	torch,
	arrow,
	maxItems,
};

void countTotalItems(const std::array<int, maxItems> &array)
{
	int totalItems{ std::reduce(array.begin(), array.end()) };
	std::cout << "The player has a total of " << totalItems << " items.\n";
}

void quiz1()
{
	std::array<int, maxItems> inventory{};
	inventory[potion] = 2;
	inventory[torch] = 5;
	inventory[arrow] = 10;

	countTotalItems(inventory);
	std::cout << "The player has " << inventory[torch] << " torches\n";
}