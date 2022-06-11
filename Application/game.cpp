#include "game.h"
#include "config.h"
#include "generator.h"

#include <iostream>

using namespace std;

Game::Game() {

    this->gameMode = MODE::PLAYER_VS_RANDOM;
}

Game::Game(MODE gameMode) {

    this->gameMode = gameMode;
}

void Game::changePlayer() {

    if(this->currentPlayer == this->playerOne) {

        this->currentPlayer = this->playerTwo;
    }
    else {

        this->currentPlayer = this->playerOne;
    }
}


void Game::play() {

    while(this->board.existSolutions()) {

        bool didMove = this->currentPlayer->makeMove();


        if(didMove) {

            changePlayer();
        }
    }

    changePlayer();

    if(this->currentPlayer == this->playerOne) {

        cout << "Player one won!\n";
    }
    else {

        cout << "Player two won!\n";
    }
}

void Game::init() {

    this->initBoard();
    this->initPlayers(&(this->board));
}

void Game::initPlayers(Board *board) {

    this->playerOne = new HumanPlayer(PLAYER_ONE_NAME, PLAYER_ONE_COLOR, board);

    if(this->gameMode == PLAYER_VS_RANDOM) {

        this->playerTwo = new RandomPlayer(PLAYER_TWO_NAME, PLAYER_TWO_COLOR, board);
    }
    else {

        this->playerTwo = new HumanPlayer(PLAYER_TWO_NAME, PLAYER_TWO_COLOR, board);
    }

    this->currentPlayer = this->playerOne;
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
