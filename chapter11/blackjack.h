#pragma once

#include <array>

/*
Let’s pretend we’re writing a card game.

a)	A deck of cards has 52 unique cards(13 card ranks of 4 suits)
	Create enumerations for the card ranks
	(2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace)
	and suits(clubs, diamonds, hearts, spades).
	Those enumerators will not be used to index arrays.
*/

enum class Rank
{
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	Jack,
	Queen,
	King,
	Ace,
	numberOfRanks,
};

enum class Suit
{
	clubs,
	diamonds,
	hearts,
	spades,
	numberOfSuits,
};

/*
b)	Each card will be represented by a struct named Card
	that contains a rank and a suit. Create the struct.
*/

struct Card
{
	Rank rank{};
	Suit suit{};
};

constexpr int numberOfCards{
	static_cast<int>(Rank::numberOfRanks) *
	static_cast<int>(Suit::numberOfSuits) };

using Deck = std::array<Card, numberOfCards>;

void printCard(const Card& card);

Deck createDeck();

void printDeck(const Deck& deck);

void shuffleDeck(Deck& deck);

int getCardValue(const Card& card);