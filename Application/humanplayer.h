#ifndef H_HUMAN_PLAYER
#define H_HUMAN_PLAYER

#include "player.h"

using namespace std;

class HumanPlayer: public Player {

public:
    HumanPlayer();
    HumanPlayer(string name, int color, Board *board);

    bool makeMove();

private:
    pair<int, int> getMouseClick() const;
    int detectClickedPoint() const;
};

#endif // H_HUMAN_PLAYER
