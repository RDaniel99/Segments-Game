#include "generator.h"
#include "config.h"

Generator::Generator() {

    srand(time(NULL));
}

Point Generator::generatePoint() {

    int randomX = rand() % WINDOW_WIDTH;
    int randomY = rand() % WINDOW_HEIGHT;

    return Point(randomX, randomY);
}

vector<Point> Generator::generatePoints(int numberOfPoints) {

    vector<Point> points;

    while(numberOfPoints != 0) {

        points.push_back(generatePoint());
        numberOfPoints--;
    }

    return points;
}
