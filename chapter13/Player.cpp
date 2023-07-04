#include "Player.h"
#include "Deck.h"

#include <string>
#include <iostream>

Player::Player(std::string_view name): m_name{name}
{}

const int Player::score()
{
	return m_score;
}

const std::string_view Player::name()
{
	return m_name;
}

void Player::printScore()
{
	std::cout << m_name << " has a score of " << m_score << ".\n";
}

Player& Player::drawCard(Deck& deck, Card::Face face)
{
	const Card& card{ deck.dealCard()};
	if (face == Card::faceup)
	{
		std::cout << m_name << " has drawn card ";
		card.print();
		std::cout << ".\n";
	}
	else
		std::cout << m_name << " has drawn a facedown card.\n";
	m_score += card.value();
	return *this;
}