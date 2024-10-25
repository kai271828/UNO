#include "../include/Card.h"

Card::Card(UnoColor color, UnoCard type)
    : color(color), type(type) {}

UnoColor Card::getColor() const {
    return color;
}

UnoCard Card::getType() const {
    return type;
}