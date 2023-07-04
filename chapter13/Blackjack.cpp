#include "Blackjack.h"

#include "Player.h"

#include <iostream>

Blackjack::Blackjack() : m_player{ "Player" }, m_dealer{ "Dealer" }
{
    m_deck.shuffle();
    if (play())
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
}

bool Blackjack::play()
{
    std::cout << "\nPlaying Blackjack!\n";
    // draw initial cards
    std::cout << "Drawing cards for " << m_dealer.name() << ".\n";
    m_dealer.drawCard(m_deck);
    m_dealer.printScore();
    m_dealer.drawCard(m_deck, Card::facedown);
    std::cout << "Drawing cards for " << m_player.name() << ".\n";
    m_player.drawCard(m_deck).drawCard(m_deck);
    m_player.printScore();

    // player's turn
    std::cout << "Player's turn.\n";
    if (playerTurn())
    {
        // The player went bust.
        return false;
    }
    std::cout << "Dealer's turn.\n";
    // dealer's turn
    if (dealerTurn())
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (m_player.score() > m_dealer.score());
}

bool Blackjack::playerTurn()
{
    while (true)
    {
        if (m_player.score() > g_maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                m_player.drawCard(m_deck);
                m_player.printScore();
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

bool Blackjack::playerWantsHit()
{
	while (true)
	{
		std::cout << "(h) to hit, or (s) to stand: ";

		char ch{};
		std::cin >> ch;

		switch (ch)
		{
		case 'h':
			return true;
		case 's':
			return false;
		}
	}
}

bool Blackjack::dealerTurn()
{
    m_dealer.printScore();
    // Draw cards until we reach the minimum value.
    while (m_dealer.score() < g_minimumDealerScore)
    {
        m_dealer.drawCard(m_deck);
        m_dealer.printScore();
    }

    // If the dealer's score is too high, they went bust.
    if (m_dealer.score() > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}