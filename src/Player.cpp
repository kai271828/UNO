#include "Player.h"
#include <iostream>

Player::Player(const std::string name)
    : name(name), points(0) {}

std::string Player::getName() const
{
    return this->name;
}
void Player::setName(const std::string name){
    this->name = name;
}

void Player::drawCards(Deck& deck, unsigned int num)
{
    deck.drawCards(num);
    std::cout << "Draw " << num << " cards from " << &deck;
}