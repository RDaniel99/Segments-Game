#include "game.h"
#include "config.h"
#include "generator.h"

#include <iostream>

using namespace std;

Game::Game() {}

void Game::changePlayer() {

    if(this->currentPlayer == &this->playerOne) {

        this->currentPlayer = &this->playerTwo;
    }
    else {

        this->currentPlayer = &this->playerOne;
    }
}

void Game::play() {

    while(this->board.existSolutions()) {

        int firstClickedPoint = detectClickedPoint();

        if(firstClickedPoint == -1) continue;

        if(this->board.getPointStatus(firstClickedPoint) == Point::Status::BLOCKED) {

            cout << "Point selected before.\n";
            continue;
        }

        cout << "Mark point (" << firstClickedPoint << ") as selected.\n";

        this->board.markPoint(firstClickedPoint, Point::Status::SELECTED);

        int secondClickedPoint = detectClickedPoint();

        while(secondClickedPoint == -1) {

            secondClickedPoint = detectClickedPoint();
        }

        cout << "Detected second point: " << secondClickedPoint << '\n';
        cout << "Status second: " << this->board.getPointStatus(secondClickedPoint) << '\n';

        if(this->board.getPointStatus(secondClickedPoint) == Point::Status::FREE) {

            cout << "Nice. You picked a pair\n";
            // TODO: Paint segment

            this->board.markPoint(firstClickedPoint, Point::Status::BLOCKED);
            this->board.markPoint(secondClickedPoint, Point::Status::BLOCKED);
            continue;
        }

        if(this->board.getPointStatus(secondClickedPoint) == Point::Status::SELECTED) {

            cout << "Unmark selected point\n";
            this->board.markPoint(secondClickedPoint, Point::Status::FREE);
            continue;
        }

        cout << "Selected point was already blocked. Unblocking first point\n";
        this->board.markPoint(firstClickedPoint, Point::Status::FREE);
    }
}

int Game::detectClickedPoint() const {

    pair<int, int> mouseClick = getMouseClick();

    for(unsigned int index = 0; index < this->board.getPoints().size(); index++) {

        Point point = this->board.getPoints()[index];

        if(point.isClicked(mouseClick.first, mouseClick.second)) {

            return index;
        }
    }

    return -1;
}

pair<int, int> Game::getMouseClick() const {

    int x, y;

    do {

        getmouseclick(WM_LBUTTONDOWN, x, y);
    } while(x < 0 && y < 0);

    cout << "Click detected on " << x << ' ' << y << '\n';

    return {x, y};
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
