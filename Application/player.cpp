#include "player.h"

Player::Player() {}

Player::Player(string name, int color) {

    this->name = name;
    this->color = color;
}

int Player::getColor() const {

    return this->color;
}

string Player::getName() const {

    return this->name;
}
