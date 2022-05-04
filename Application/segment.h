#ifndef H_SEGMENT
#define H_SEGMENT

#include "point.h"
#include "graphics.h"

class Segment {

    public:
        Segment();
        Segment(Point a, Point b);
        Point getA() const;
        Point getB() const;

        void paint(int color = DEFAULT_COLOR) const;

    private:
        Point a, b;
};

#endif // H_SEGMENT
