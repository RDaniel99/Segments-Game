#ifndef H_BOARD
#define H_BOARD

#include <vector>
#include "point.h"
#include "segment.h"

using namespace std;

class Board {

    public:
        Board();
        Board(vector<Point> points);
        void addSegment(Segment &segment);

    private:
        vector<Point> points;
        vector<Segment> segments;
};

#endif // H_BOARD
