#pragma once

#include "Deck.h"

#include <string>

class Player
{
public:
	Player(std::string_view name);
	Player& drawCard(Deck& deck, Card::Face face=Card::faceup);
	const int score();
	const std::string_view name();
	void printScore();
private:
	int m_score{0};
	const std::string_view m_name{};
};