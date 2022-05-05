#include "point.h"
#include "config.h"

#include <iostream>

using namespace std;

Point::Point() {}

Point::Point(int x, int y) {

    this->x = x;
    this->y = y;
    this->status = FREE;
}

int Point::getX() const {

    return this->x;
}

int Point::getY() const {

    return this->y;
}

Point::Status Point::getStatus() const {

    return this->status;
}

void Point::setStatus(Point::Status status) {

    this->status = status;
}

bool Point::isClicked(int x, int y) const {

    if(abs(x - this->x) > DEFAULT_RADIUS) return false;
    if(abs(y - this->y) > DEFAULT_RADIUS) return false;

    int distanceFromCenterSquared = (x - this->x) * (x - this->x) + (y - this->y) * (y - this->y);

    // cout << "Distance from me: " << distanceFromCenterSquared << '\n';

    return distanceFromCenterSquared <= DEFAULT_RADIUS * DEFAULT_RADIUS;
}

void Point::paint(int color) const {

    setcolor(color);

    circle(x, y, DEFAULT_RADIUS);

    setfillstyle(SOLID_FILL, color);

    floodfill(x, y, color);
}
