#include "board.h"

Board::Board() {}

Board::Board(vector<Point> points) {

    this->points = points;
    this->segments.clear();
}

void Board::addSegment(Segment &segment) {

    this->segments.push_back(segment);
}
