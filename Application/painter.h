#ifndef H_PAINTER
#define H_PAINTER

#include "point.h"
#include "segment.h"
#include "config.h"

class Painter {

    public:
        Painter();
        void paintPoint(Point &point, int color = DEFAULT_COLOR);
        void paintSegment(Segment &segment, int color = DEFAULT_COLOR);
};

#endif // H_PAINTER
