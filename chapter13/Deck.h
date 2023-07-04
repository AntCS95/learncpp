#pragma once

#include "Card.h"

#include <array>

class Deck
{
public:
	Deck();

	void shuffle();
	void print() const;
	const Card& dealCard();

private:
	std::array<Card, 52> m_deck{};
	size_t m_cardIndex{};

	void create();
	
};