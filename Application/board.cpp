#include "board.h"

#include <iostream>

using namespace std;

Board::Board() {}

Board::Board(vector<Point> points) {

    this->points = points;
    this->segments.clear();
}

void Board::addSegment(Segment &segment) {

    this->segments.push_back(segment);
}

vector<Point> Board::getPoints() const {

    return this->points;
}

bool Board::markPoint(int index, Point::Status status) {

    if(index < 0 || index >= this->points.size()) return false;

    this->points[index].setStatus(status);

    return true;
}

Point::Status Board::getPointStatus(int index) const {

    if(index < 0 || index >= this->points.size()) return Point::Status::BLOCKED;

    return this->points[index].getStatus();
}

bool Board::existSolutions() const {

    if(this->points.size() - this->segments.size() * 2 <= 1) return false;

    for(auto pointOne: this->points) {

        for(auto pointTwo: this->points) {

            if(pointOne.getX() == pointTwo.getX() &&
               pointOne.getY() == pointTwo.getY()) continue;

            if(canUnion(pointOne, pointTwo)) {

                // cout << "Can union " << pointOne.getX() << ' ' << pointOne.getY() << ' ' << pointTwo.getX() << ' ' << pointTwo.getY() << '\n';
                return true;
            }
        }
    }

    return false;
}

bool Board::canUnion(const Point& pointOne, const Point& pointTwo) const {

    for(auto segment: this->segments) {

        if(doesIntersect(segment, pointOne, pointTwo)) {

            return false;
        }
    }

    return true;
}

bool Board::doesIntersect(const Segment& segment, const Point& pointOne, const Point& pointTwo) const {

    int orientationOne = computeOrientation(segment.getA(), segment.getB(), pointOne);
    int orientationTwo = computeOrientation(segment.getA(), segment.getB(), pointTwo);
    int orientationThree = computeOrientation(pointOne, pointTwo, segment.getA());
    int orientationFour  = computeOrientation(pointOne, pointTwo, segment.getB());

    if(orientationOne != orientationTwo && orientationThree != orientationFour) return true;

    if(orientationOne == 0 && isPointOnSegment(segment.getA(), segment.getB(), pointOne)) return true;
    if(orientationTwo == 0 && isPointOnSegment(segment.getA(), segment.getB(), pointTwo)) return true;
    if(orientationThree == 0 && isPointOnSegment(pointOne, pointTwo, segment.getA())) return true;
    if(orientationFour == 0 && isPointOnSegment(pointOne, pointTwo, segment.getB())) return true;

    return false;
}

bool Board::isPointOnSegment(const Point& S1, const Point& S2, const Point& P) const {

    bool ok = true;

    ok = ok && (max(S1.getX(), S2.getX()) >= P.getX());
    ok = ok && (min(S1.getX(), S2.getX()) <= P.getX());
    ok = ok && (max(S1.getY(), S2.getY()) <= P.getY());
    ok = ok && (min(S1.getY(), S2.getY()) <= P.getY());

    return ok;
}

int Board::computeOrientation(const Point& A, const Point& B, const Point& C) const {

    int orientation =   (B.getY() - A.getY()) * (C.getX() - B.getX()) -
                        (B.getX() - A.getX()) * (C.getY() - B.getY());

    if(!orientation) return 0;

    return orientation / abs(orientation);
}
