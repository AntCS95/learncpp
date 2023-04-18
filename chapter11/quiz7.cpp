/*
a)  Alright, challenge time! Let’s write a simplified version of Blackjack.
    If you’re not already familiar with Blackjack,
    the Wikipedia article for Blackjack has a summary.

Here are the rules for our version of Blackjack:

    - The dealer gets one card to start (in real life, the dealer gets two,
    but one is face down so it doesn’t matter at this point).
    - The player gets two cards to start.
    - The player goes first.
    - A player can repeatedly “hit” or “stand”.
    - If the player “stands”, their turn is over,
    and their score is calculated based on the cards they have been dealt.
    - If the player “hits”, they get another card and the value of that card
    is added to their total score.
    - An ace normally counts as a 1 or an 11
    (whichever is better for the total score).
    For simplicity, we’ll count it as an 11 here.
    - If the player goes over a score of 21, they bust and lose immediately.
    - The dealer goes after the player.
    - The dealer repeatedly draws until they reach a score of 17 or more,
    at which point they stand.
    - If the dealer goes over a score of 21,
    they bust and the player wins immediately.
    - Otherwise, if the player has a higher score than the dealer,
    the player wins. Otherwise, the player loses
    (we’ll consider ties as dealer wins for simplicity).

In our simplified version of Blackjack, we’re not going to keep track
of which specific cards the player and the dealer have been dealt.
We’ll only track the sum of the values of the cards they have been dealt
for the player and dealer. This keeps things simpler.

Start with the code you wrote in quiz #6.
Create a function named playBlackjack(). This function should:

    Accept a shuffled deck of cards as a parameter.
    Implement Blackjack as defined above (note: you can define other functions
    to help with this).
    Returns true if the player won, and false if they lost.

Also write a main() function to play a single game of Blackjack.
*/

#include <numeric>
#include <vector>
#include <iostream>

#include "blackjack.h"

using Deck = std::array<Card, numberOfCards>;

int drawCard(const Deck &deck)
{
	static int cardID{ 0 };
    auto& card{ deck[cardID] };
    std::cout << "Card ";
    printCard(card);
    std::cout << " was drawn\n";
	++cardID;
	return getCardValue(card);
}

using Hand = std::vector<int>;

Hand updateHand(Hand& hand, const Deck& deck)
{
    int cardValue{ drawCard(deck) };
    //draws and ace
    if (cardValue == 11)
    {
        Hand newHand{};
        for (const auto value : hand)
        {
            newHand.push_back(value + 1);
            newHand.push_back(value + 11);
        }
        return newHand;
    }
    //draws other than ace
    else
    {
        for (auto& value : hand)
        {
            value += cardValue;
        }
        return hand;
    }
}

constexpr int maxValue{ 21 };
constexpr int dealerStandValue{ 17 };

//binary operators
int bestValue(int x, int y)
{
    return ((y > x) && (y <= maxValue) ? y : x);
}

int getBestValue(Hand& hand)
{
    return std::reduce(hand.begin(), hand.end(), hand[0], bestValue);
}


void playBlackjack(Deck& deck)
{
    //initialize hands
    Hand dealerHand{ 0 };
    Hand playerHand{ 0 };
    //draw card for dealer and update hand
    dealerHand = updateHand(dealerHand, deck);
    std::cout << "Dealer got a value of " << getBestValue(dealerHand) << '\n';
    //players comes into play
    //draws two cards
    playerHand = updateHand(playerHand, deck);
    playerHand = updateHand(playerHand, deck);
    //decisive iteration
    bool win{};
    bool busted{ false };
    char decision{};
    while (true)
    {
        do
        {
            std::cout << "Your current value is " << getBestValue(playerHand);
            std::cout << '\n';
            std::cout << "Draw another card (y/n)? ";
            std::cin >> decision;
        } while (!(decision == 'y' || decision == 'n'));

        if (decision == 'y')
        {
            std::cout << "Your choice was to hit, drawing new card\n";
            playerHand = updateHand(playerHand, deck);

            if (getBestValue(playerHand) > maxValue)
            {
                std::cout << "Ups, you busted! (" <<
                    getBestValue(playerHand) <<
                    ")\n";
                win = false;
                busted = true;
                break;
            }
        }
        else
        {
            std::cout << "Your choice was to stand, your final best value is ";
            std::cout << getBestValue(playerHand);
            std::cout << '\n';
            break;
        }
    }
    if (!busted)
    {
        //dealer comes into play
        dealerHand = updateHand(dealerHand, deck);
        while (getBestValue(dealerHand) < dealerStandValue)
        {
            std::cout << "Dealer hits with a value of "
                << getBestValue(dealerHand) << '\n';
            dealerHand = updateHand(dealerHand, deck);
            if (getBestValue(dealerHand) > maxValue)
            {
                std::cout << "Ups, dealer busted! (" <<
                    getBestValue(dealerHand) <<
                    ")\n";
                win = true;
                busted = true;
            }
        }
        if (getBestValue(dealerHand) <= maxValue)
        {
            std::cout << "Dealer stands with a value of "
                << getBestValue(dealerHand) << '\n';
        }
    }
    //decide winner if neither player busted
    if (!busted)
    {
        win = (getBestValue(playerHand) > getBestValue(dealerHand) ?
            true : false);
    }

    if (win)
    {
        std::cout << "Congratulations! You won ("
            << getBestValue(playerHand) << '-' << getBestValue(dealerHand)
            << ")\n";
    }
    else
    {
        std::cout << "Sorry! You lost (" 
            << getBestValue(playerHand) << '-' << getBestValue(dealerHand)
            << ")\n";
    }

    std::cout << "Game ended\n";
}

void quiz7()
{
    Deck deck{ createDeck() };


    char decision{};
    while (true)
    {
        shuffleDeck(deck);
        printDeck(deck);
        playBlackjack(deck);
        do
        {
            std::cout << "Play again (y/n)? ";
            std::cin >> decision;
        } while (!(decision == 'y' || decision == 'n'));
        if (decision == 'n')
        {
            break;
        }
    }
    std::cout << "Goodbye!\n";
}