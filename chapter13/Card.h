#pragma once

class Card
{
public:

    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

    enum Face
    {
        faceup,
        facedown
    };

    Card(Rank rank=rank_ace, Suit suit=club);
    void print() const;
    int value() const;

private:

    Suit m_suit{};
    Rank m_rank{};

};