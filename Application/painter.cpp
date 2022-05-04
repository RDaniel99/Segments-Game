#include "painter.h"

#include <iostream>

using namespace std;

Painter::Painter() {}

void Painter::paintPoint(Point &point, int color) {

    setcolor(color);

    circle(point.getX(), point.getY(), DEFAULT_RADIUS);

    setfillstyle(SOLID_FILL, color);

    floodfill(point.getX(), point.getY(), color);
}

void Painter::paintSegment(Segment &segment, int color) {

    line(segment.getA().getX(), segment.getA().getY(),
         segment.getB().getX(), segment.getB().getY());
}
