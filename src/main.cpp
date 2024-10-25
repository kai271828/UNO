#include <iostream>
#include <vector>
#include "Card.h"

int main()
{
    
    std::vector<Card> cards;
    for(size_t i = 0; i < 15; i++){
        for (size_t j = 0; j < 4; j++){
            Card card(UnoColor::Blue, UnoCard::DrawTwo);
        }
    }
    return 0;
}