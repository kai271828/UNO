#include <iostream>

#include <Card.h>
#include <Uno.h>

Card::Card(UnoColor color, UnoType type)
    : color(color), type(type) {}

UnoColor Card::getColor() const {
    return color;
}

UnoType Card::getType() const {
    return type;
}


std::string typeToString(UnoType card)
{
    switch (card) {
        case UnoType::Zero: return "Zero";
        case UnoType::One: return "One";
        case UnoType::Two: return "Two";
        case UnoType::Three: return "Three";
        case UnoType::Four: return "Four";
        case UnoType::Five: return "Five";
        case UnoType::Six: return "Six";
        case UnoType::Seven: return "Seven";
        case UnoType::Eight: return "Eight";
        case UnoType::Nine: return "Nine";
        case UnoType::Skip: return "Skip";
        case UnoType::Reverse: return "Reverse";
        case UnoType::DrawTwo: return "DrawTwo";
        case UnoType::Wild: return "Wild";
        case UnoType::WildDrawFour: return "WildDrawFour";
        default: return "Unknown";
    }
}

std::string colorToString(UnoColor card) {
    switch (card) {
        case UnoColor::Red: return "Red";
        case UnoColor::Yellow: return "Yellow";
        case UnoColor::Green: return "Green";
        case UnoColor::Blue: return "Blue";
        case UnoColor::Black: return "Black";
        default: return "Unknown";
    }
}