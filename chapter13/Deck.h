#pragma once

#include "Card.h"

#include <array>

class Deck
{
public:
	Deck();

	void shuffle();
	void print() const;

private:
	std::array<Card, 52> m_deck{};

	void create();
	
};