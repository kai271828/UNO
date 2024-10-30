#pragma once
#include <vector>
#include <memory>

#include <Card.h>
#include <Deck.h>
#include <DiscardPile.h>
#include <Uno.h>

class Player {
public:
    Player(const std::string);
    std::string getName() const;
    void setName(const std::string);
    unsigned getPoints() const;
    void drawCards(Deck&, unsigned);
    void act(Deck&, DiscardPile&, UnoColor&, UnoOrder&);
    bool hasNoCard();
    template <std::size_t N>
    void winPoints(const std::array<Player, N>&);

private:
    std::string name;
    std::vector<std::unique_ptr<Card>> hand;
    unsigned points;
};