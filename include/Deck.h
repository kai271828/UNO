#pragma once
#include <vector>

class Deck {
public:
    Deck();
    void shuffle();
    int getDealer(const unsigned int&);
    std::vector<std::unique_ptr<Card>> drawCards(unsigned int);
    void reset(DiscardPile&);

private:
    std::vector<std::unique_ptr<Card>> cards;
    friend class DiscardPile;
};