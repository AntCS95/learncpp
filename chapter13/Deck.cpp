#include "Deck.h"
#include "Card.h"

//#include "Random.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

Deck::Deck()
{
    create();
}

void Deck::create()
{
    size_t index{ 0 };
    for (int suit{}; suit < Card::max_suits; ++suit)
    {
        for (int rank{ 0 }; rank < Card::max_ranks; ++rank)
        {
            m_deck[index] = 
            Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
            ++index;
        }
    }
}

void Deck::print() const
{
    for (const Card &card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle()
{
    using std::mt19937;
    using std::time;
    static mt19937 mt{ static_cast<mt19937::result_type>(time(nullptr)) };
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    const Card& card { m_deck[m_cardIndex++] };
    //std::cout << "The card ";
    //card.print();
    //std::cout << " was dealed.\n";
    return card;
}