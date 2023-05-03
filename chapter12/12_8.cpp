#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

int getNumber()
{
	int x{};
	std::cin >> x;
	return x;
}

int getRandomNumber()
{
	static std::random_device rd;
	static std::mt19937 gen{ rd() };
	static std::uniform_int_distribution dist(2, 4);
	return dist(gen);
}

using SquaresList = std::vector<int>;

SquaresList createSquaresList(const int start, const int amount, const int mult)
{
	SquaresList list(amount);
	int count{ start };
	for (auto& number : list)
	{
		number = count*count*mult;
		++count;
	}
	return list;
}

bool eraseNumber(const int number, SquaresList& list)
{
	auto pos{ std::find(list.begin(), list.end(), number) };
	if (pos == list.end()) return false;
	else
	{
		list.erase(pos);
		return true;
	}
}

int getClosest(const int number, const SquaresList& list)
{
	constexpr int threshold{ 4 };
	static auto absDiff{ [=](int x, int y) {
		return abs(x - number) < abs(y-number); } };
	auto pos{ std::min_element(list.begin(), list.end(), absDiff) };
	if (abs(*pos - number) > threshold) return -1;
	else return *pos;
}

void squareNumbersGame()
{
	//user input
	std::cout << "Start where? ";
	int start{ getNumber() };
	std::cout << "How many? ";
	int amount{ getNumber() };
	//random multiplier
	int mult{ getRandomNumber() };
	//create list of numbers
	SquaresList list{ createSquaresList(start, amount, mult) };
	//start the game
	std::cout << "I generated " << amount << " square numbers. Do you know "
		"what each number is after multiplying it by " << mult << " ?\n";
	int guess{};
	bool win{ true };
	//keep playing while still guesses to make
	while (list.size()>0)
	{
		//get guess
		guess = getNumber();

		//case guess is correct, congratulate and print remaining guesses
		//keep playing
		if (eraseNumber(guess, list))
		{
			if (list.size() > 0)
			{
				std::cout << "Nice! " << list.size() << " numbers left.\n";
			}
		}
		//case gues is uncorrect, print closest number if any
		//then you lose the game and exit
		else
		{
			std::cout << guess << " is wrong!";
			const int closest{ getClosest(guess, list) };
			if (closest >= 0)
			{
				std::cout << " Try " << closest << " next time.\n";
			}
			else std::cout << '\n';
			win = false;
			break;
		}
	}
	//game over
	if (win)
	{
		std::cout << "Nice! You found all numbers, good job!";
	}
}