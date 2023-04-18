#include <iostream>
#include <array>
#include <algorithm>
#include <random>

#include "blackjack.h"

/*
c)	Create a printCard() function that takes a const Card reference
	as a parameter and prints the card rank and suit as a 2-letter code
	(e.g. the jack of spades would print as JS).
*/

char getRank(Rank rank)
{
	switch (rank)
	{
	case Rank::two: return '2';
	case Rank::three: return '3';
	case Rank::four: return '4';
	case Rank::five: return '5';
	case Rank::six: return '6';
	case Rank::seven: return '7';
	case Rank::eight: return '8';
	case Rank::nine: return '9';
	case Rank::ten: return 'T';
	case Rank::Jack: return 'J';
	case Rank::Queen: return 'Q';
	case Rank::King: return 'K';
	case Rank::Ace: return 'A';
	}
}

char getSuit(Suit suit)
{
	switch (suit)
	{
	case Suit::clubs: return 'C';
	case Suit::diamonds: return 'D';
	case Suit::hearts: return 'H';
	case Suit::spades: return 'S';
	}
}

void printCard(const Card &card)
{
	std::cout << getRank(card.rank) << getSuit(card.suit);
}

/*
d)	A deck of cards has 52 cards. Create an array (using std::array)
	to represent the deck of cards, and initialize it with one of each card.
	Do this in a function named createDeck and call createDeck from main.
	createDeck should return the deck to main.

	Hint: Use static_cast if you need to convert an integer into an
	enumerated type.
*/

Deck createDeck()
{
	int numberOfRanks{ static_cast<int>(Rank::numberOfRanks) };
	int numberOfSuits{ static_cast<int>(Suit::numberOfSuits) };
	Deck deck {};
	for (int suitID{ 0 }; suitID < numberOfSuits; ++suitID)
	{
		Suit suit{ static_cast<Suit>(suitID) };
		for (int rankID{ 0 }; rankID < numberOfRanks; ++rankID)
		{
			Rank rank{ static_cast<Rank>(rankID) };
			Card card{rank, suit };
			deck[rankID + suitID * numberOfRanks] = card;
		}
	}
	return deck;
}

/*
e)	Write a function named printDeck() that takes the deck as a
	const reference parameter and prints the cards in the deck.
	Use a range - based for - loop.
	When you can printDeck with the deck you generated in the previous task,
	the output should be:

	2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC
	2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AD
	2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH AH
	2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS AS

	If you used different characters, that’s fine too.
*/

void printDeck(const Deck &deck)
{
	for (auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

/*
f)	Write a function named shuffleDeck to shuffle the deck of cards
	using std::shuffle. Update your main function to shuffle the deck
	and print out the shuffled deck.

	Reminder: Only seed your random number generator once.
*/

void shuffleDeck(Deck &deck)
{
	using std::mt19937;
	static mt19937 mt{ static_cast<mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

/*
g)	Write a function named getCardValue() that returns the value of a Card
	(e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10.
	Assume an Ace is worth 11).
*/

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case Rank::two: return 2;
	case Rank::three: return 3;
	case Rank::four: return 4;
	case Rank::five: return 5;
	case Rank::six: return 6;
	case Rank::seven: return 7;
	case Rank::eight: return 8;
	case Rank::nine: return 9;
	case Rank::ten:
	case Rank::Jack:
	case Rank::Queen:
	case Rank::King: return 10;
	case Rank::Ace: return 11;
	}
}

void quiz6()
{
	auto deck{ createDeck() };
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);
	std::cout << getCardValue(deck[0]);
}