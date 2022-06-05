#include "randomplayer.h"

using namespace std;

RandomPlayer::RandomPlayer() {}

RandomPlayer::RandomPlayer(string name, int color, Board* board) {

    setName(name);
    setColor(color);
    setBoard(board);
}

bool RandomPlayer::makeMove() {

    if(!this->board->existSolutions()) {
        return false;
    }

    vector<Point> points = this->board->getPoints();

    for(int i = 0; i < points.size() - 1; i++) {
        for(int j = i + 1; j < points.size(); j++) {
            if(points[i].getStatus() == Point::Status::FREE &&
               points[j].getStatus() == Point::Status::FREE &&
               this->board->canUnion(points[i], points[j])) {

                this->board->markPoint(i, Point::Status::BLOCKED);
                this->board->markPoint(j, Point::Status::BLOCKED);

                points[i].paint(getColor());
                points[j].paint(getColor());

                Segment segment(points[i], points[j]);
                this->board->addSegment(segment);
                segment.paint(getColor());
                return true;
            }
        }
    }

    return false;
}
