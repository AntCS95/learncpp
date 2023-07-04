#pragma once

#include "Player.h"
#include "Deck.h"

class Blackjack
{
public:
	Blackjack();
	
private:
	Player m_player;
	Player m_dealer;
	Deck m_deck;
	static constexpr int g_maximumScore{ 21 };
	static constexpr int g_minimumDealerScore{ 17 };

	bool playerTurn();
	bool playerWantsHit();
	bool dealerTurn();
	bool play();
};