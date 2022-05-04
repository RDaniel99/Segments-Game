#include "game.h"
#include "config.h"
#include "generator.h"

Game::Game() {}

void Game::changePlayer() {

    if(this->currentPlayer == &this->playerOne) {

        this->currentPlayer = &this->playerTwo;
    }
    else {

        this->currentPlayer = &this->playerOne;
    }
}

void Game::init() {

    this->initPlayers();
    this->initBoard();
}

void Game::initPlayers() {

    this->playerOne = Player(PLAYER_ONE_NAME, PLAYER_ONE_COLOR);
    this->playerTwo = Player(PLAYER_TWO_NAME, PLAYER_TWO_COLOR);
}

void Game::initBoard() {

    Generator generator;

    vector<Point> points = generator.generatePoints(DEFAULT_NUMBER_OF_POINTS);

    this->board = Board(points);

    paintPoints(points);
}

void Game::paintPoints(vector<Point> &points) const {

    for(auto point: points) {

        point.paint();
    }
}
