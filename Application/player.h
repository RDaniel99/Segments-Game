#ifndef H_PLAYER
#define H_PLAYER

#include <string>
#include "board.h"

using namespace std;

class Player {

    public:
        Player();
        Player(string name, int color, Board *board);

        int getColor() const;
        string getName() const;

        void setColor(int color);
        void setName(string name);
        void setBoard(Board *board);

        virtual bool makeMove();

    protected:
        Board* board;

    private:
        int color;
        string name;

};

#endif // H_PLAYER
