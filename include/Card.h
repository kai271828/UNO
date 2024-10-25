#pragma once
#include <iostream>

enum class UnoColor {
    Red,
    Yello,
    Green,
    Blue,
    WildColor,
};

enum class UnoCard {
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Skip,
    Reverse,
    DrawTwo,
    Wild,
    WildDrawFour
};

class Card {
public:
    Card(UnoColor color, UnoCard type);
    UnoColor getColor() const;
    UnoCard getType() const;

private:
    UnoColor color;
    UnoCard type;
};