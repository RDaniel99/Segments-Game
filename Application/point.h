#ifndef H_POINT
#define H_POINT

#include "graphics.h"
#include "config.h"

class Point {

    public:
        enum Status {
            FREE,
            SELECTED,
            BLOCKED
        };

        Point();
        Point(int x, int y);
        int getX() const;
        int getY() const;
        Status getStatus() const;
        void setStatus(Status status);
        bool isClicked(int x, int y) const;

        void paint(int color = DEFAULT_COLOR) const;

    private:

        int x, y;
        Status status;
};

#endif // H_POINT
