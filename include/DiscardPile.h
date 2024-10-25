#pragma once
#include <vector>

class DiscardPile {
public:
    DiscardPile(Deck& deck);
    UnoColor getTopColor();
    UnoType getTopType();
    void addCard(std::unique_ptr<Card>);

private:
    std::vector<std::unique_ptr<Card>> pile;
    friend class Deck;
};