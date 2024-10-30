#include <array>
#include <memory>
#include <algorithm>

#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"
#include "Uno.h"

inline void nextPlayer(int& playerCoutner, const unsigned int numPlayer, const UnoOrder order)
{
    /*
    * Move the playerCounter correctly.
    */
    if(order == UnoOrder::Clockwise){
        playerCoutner++;
        if(playerCoutner >= numPlayer){
            playerCoutner = 0;
        }
    }
    else{
        playerCoutner--;
        if(playerCoutner < 0){
            playerCoutner = numPlayer - 1;
        }
    }
}

template <std::size_t N>
void game(const std::array<Player, N>& players)
{   
    UnoOrder order = UnoOrder::Clockwise;
    UnoColor color;

    // While none gets 500 points
    while(true){
        for(auto player: players){
            if(player.getPoints() > 500){
                break;
            }
        }
    
        // Initialize the deck
        std::unique_ptr<Deck> deckPtr = std::make_unique<Deck>();

        // Shuffle
        deckPtr->shuffle();

        // Decide the dealer
        int playerCounter = deckPtr->getDealer(N);

        // Shuffle again
        deckPtr->shuffle();

        // Deal the cards
        for (size_t i = 0; i < 7; i++){
            for(size_t j = 0; j < N; j++){
                players[playerCounter].drawCards(*deckPtr, 1);
                nextPlayer(playerCounter, N, order);
            }
        }
        nextPlayer(playerCounter, N, order);

        // Set the discard pile
        std::unique_ptr<DiscardPile> pilePtr = std::make_unique<DiscardPile>(*deckPtr);

        // If the first discard is action or wild
            /*
            * Skip: Player to dealer's left misses a turn
            * Reverse: Dealer plays first; play proceeds counterclockwise
            * DrawTwo: Player to dealer's left draws two cards and misses a turn
            * Wild: Player to dealer's left declares the first color to be matched and takes the first turn
            * WildDrawFour: Card is returned to the deck, then a new card is laid down into the discard pile (deck may be reshuffled first if needed)
            */
        if(pilePtr->getTopType() == UnoType::Skip){
            nextPlayer(playerCounter, N, order);
        }
        else if(pilePtr->getTopType() == UnoType::Reverse){
            order = (order == UnoOrder::Clockwise ? UnoOrder::Counterclockwise : UnoOrder::Clockwise);
            nextPlayer(playerCounter, N, order);
        }
        else if(pilePtr->getTopType() == UnoType::DrawTwo){
            players[playerCounter].drawCards(*deckPtr, 2);
            nextPlayer(playerCounter, N, order);
        }
        else if(pilePtr->getTopType() == UnoType::Wild){
            players[playerCounter].declare(color);
        }
        else if(pilePtr->getTopType() == UnoType::WildDrawFour){
            while(pilePtr->getTopType() == UnoType::WildDrawFour){
                deckPtr->reset(*pilePtr);
            }
            
        }

        // If the first discard is a normal card, the player to the dealer's left plays first
        color = pilePtr->getTopColor();

        // For each player 
        while (true){
            /*
            * 1. play one card matching the discard in color, number, or symbol
            * 2. play a Wild card, or a Wild Draw Four card (if allowed).
            * 3. draw the top card from the deck, and optionally play it if possible
            */
            players[playerCounter].act(*deckPtr, *pilePtr, color, order);
            
            // If get rid of their last card, wins the hand and scores points for the cards held by each other player.
            if (players[playerCounter].hasNoCard()){
                players[playerCounter].winPoints(players);
                break;
            }

            nextPlayer(playerCounter, N, order);
        }
    }
        
}