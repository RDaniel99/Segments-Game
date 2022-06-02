#include "game.h"
#include "config.h"
#include "generator.h"

#include <iostream>

using namespace std;

Game::Game() {}

void Game::changePlayer() {

    if(this->currentPlayer == this->playerOne) {

        this->currentPlayer = this->playerTwo;
    }
    else {

        this->currentPlayer = this->playerOne;
    }
}


void Game::play() {

/*
    while(this->board.existSolutions()) {

        int firstClickedPoint = detectClickedPoint();

        if(firstClickedPoint == -1) continue;

        if(this->board.getPointStatus(firstClickedPoint) == Point::Status::BLOCKED) {

            cout << "Point selected before.\n";
            continue;
        }

        cout << "Mark point (" << firstClickedPoint << ") as selected.\n";

        this->board.markPoint(firstClickedPoint, Point::Status::SELECTED);

        this->board.getPoints()[firstClickedPoint].paint(this->currentPlayer->getColor());

        int secondClickedPoint = detectClickedPoint();

        while(secondClickedPoint == -1) {

            secondClickedPoint = detectClickedPoint();
        }

        cout << "Detected second point: " << secondClickedPoint << '\n';
        cout << "Status second: " << this->board.getPointStatus(secondClickedPoint) << '\n';

        if(this->board.getPointStatus(secondClickedPoint) == Point::Status::FREE) {

            if(!this->board.canUnion(this->board.getPoints()[firstClickedPoint],
                                     this->board.getPoints()[secondClickedPoint])) {

                cout << "Segment intersects with another segments. Unmark points\n";

                this->board.markPoint(firstClickedPoint, Point::Status::FREE);
                this->board.getPoints()[firstClickedPoint].paint();
                continue;
            }

            cout << "Nice. You picked a good pair\n";
            // TODO: Paint segment

            this->board.markPoint(firstClickedPoint, Point::Status::BLOCKED);
            this->board.markPoint(secondClickedPoint, Point::Status::BLOCKED);

            this->board.getPoints()[secondClickedPoint].paint(this->currentPlayer->getColor());

            Segment segment(this->board.getPoints()[firstClickedPoint],
                            this->board.getPoints()[secondClickedPoint]);

            this->board.addSegment(segment);
            segment.paint(this->currentPlayer->getColor());

            changePlayer();

            continue;
        }

        if(this->board.getPointStatus(secondClickedPoint) == Point::Status::SELECTED) {

            cout << "Unmark selected point\n";
            this->board.markPoint(secondClickedPoint, Point::Status::FREE);

            this->board.getPoints()[secondClickedPoint].paint();
            continue;
        }

        cout << "Selected point was already blocked. Unblocking first point\n";
        this->board.markPoint(firstClickedPoint, Point::Status::FREE);
        this->board.getPoints()[firstClickedPoint].paint();
    }
*/

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

/*int Game::detectClickedPoint() const {

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
}*/

void Game::init() {

    this->initBoard();
    this->initPlayers(&(this->board));
}

void Game::initPlayers(Board *board) {

    this->playerOne = new HumanPlayer(PLAYER_ONE_NAME, PLAYER_ONE_COLOR, board);
    this->playerTwo = new HumanPlayer(PLAYER_TWO_NAME, PLAYER_TWO_COLOR, board);

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
