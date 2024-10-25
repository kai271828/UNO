#pragma once

class Card {
public:
    Card(UnoColor color, UnoType type);
    UnoColor getColor() const;
    UnoType getType() const;

private:
    UnoColor color;
    UnoType type;
};