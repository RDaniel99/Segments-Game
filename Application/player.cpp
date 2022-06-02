#include "player.h"

Player::Player() {}

Player::Player(string name, int color, Board *board) {

    this->name = name;
    this->color = color;
    this->board = board;
}

int Player::getColor() const {

    return this->color;
}

string Player::getName() const {

    return this->name;
}

void Player::setColor(int color) {

    this->color = color;
}

void Player::setName(string name) {

    this->name = name;
}

void Player::setBoard(Board *board) {

    this->board = board;
}

bool Player::makeMove() {

}
