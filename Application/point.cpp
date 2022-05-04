#include "point.h"
#include "config.h"

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

void Point::paint(int color) const {

    setcolor(color);

    circle(x, y, DEFAULT_RADIUS);

    setfillstyle(SOLID_FILL, color);

    floodfill(x, y, color);
}
