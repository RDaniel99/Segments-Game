#ifndef H_GENERATOR
#define H_GENERATOR

#include <vector>
#include "point.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Generator {

    public:
        Generator();
        vector<Point> generatePoints(int numberOfPoints);

    private:
        Point generatePoint();
};

#endif // H_GENERATOR
