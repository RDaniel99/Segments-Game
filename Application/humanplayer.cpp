#include "humanplayer.h"

#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer() {}

HumanPlayer::HumanPlayer(string name, int color, Board* board) {

    setName(name);
    setColor(color);
    setBoard(board);
}

bool HumanPlayer::makeMove() {

    while(true) {

        int firstClickedPoint = detectClickedPoint();

        if(firstClickedPoint == -1) continue;

        if(this->board->getPointStatus(firstClickedPoint) == Point::Status::BLOCKED) {

            cout << "Point selected before.\n";
            continue;
        }

        cout << "Mark point (" << firstClickedPoint << ") as selected.\n";

        this->board->markPoint(firstClickedPoint, Point::Status::SELECTED);

        this->board->getPoints()[firstClickedPoint].paint(this->getColor());

        int secondClickedPoint = detectClickedPoint();

        while(secondClickedPoint == -1) {

            secondClickedPoint = detectClickedPoint();
        }

        cout << "Detected second point: " << secondClickedPoint << '\n';
        cout << "Status second: " << this->board->getPointStatus(secondClickedPoint) << '\n';

        if(this->board->getPointStatus(secondClickedPoint) == Point::Status::FREE) {

            if(!this->board->canUnion(this->board->getPoints()[firstClickedPoint],
                                     this->board->getPoints()[secondClickedPoint])) {

                cout << "Segment intersects with another segments. Unmark points\n";

                this->board->markPoint(firstClickedPoint, Point::Status::FREE);
                this->board->getPoints()[firstClickedPoint].paint();
                return false;
            }

            cout << "Nice. You picked a good pair\n";
            // TODO: Paint segment

            this->board->markPoint(firstClickedPoint, Point::Status::BLOCKED);
            this->board->markPoint(secondClickedPoint, Point::Status::BLOCKED);

            this->board->getPoints()[secondClickedPoint].paint(this->getColor());

            Segment segment(this->board->getPoints()[firstClickedPoint],
                            this->board->getPoints()[secondClickedPoint]);

            this->board->addSegment(segment);
            segment.paint(this->getColor());

            return true;
        }

        if(this->board->getPointStatus(secondClickedPoint) == Point::Status::SELECTED) {

            cout << "Unmark selected point\n";
            this->board->markPoint(secondClickedPoint, Point::Status::FREE);

            this->board->getPoints()[secondClickedPoint].paint();
            return false;
        }

        cout << "Selected point was already blocked. Unblocking first point\n";
        this->board->markPoint(firstClickedPoint, Point::Status::FREE);
        this->board->getPoints()[firstClickedPoint].paint();

        return false;
    }

    return false;
}

int HumanPlayer::detectClickedPoint() const {

    pair<int, int> mouseClick = getMouseClick();

    for(unsigned int index = 0; index < this->board->getPoints().size(); index++) {

        Point point = this->board->getPoints()[index];

        if(point.isClicked(mouseClick.first, mouseClick.second)) {

            return index;
        }
    }

    return -1;
}

pair<int, int> HumanPlayer::getMouseClick() const {

    int x, y;

    do {

        getmouseclick(WM_LBUTTONDOWN, x, y);
    } while(x < 0 && y < 0);

    cout << "Click detected on " << x << ' ' << y << '\n';

    return {x, y};
}
