#ifndef H_RANDOM_PLAYER
#define H_RANDOM_PLAYER

#include "player.h"

class RandomPlayer: public Player {

public:
    RandomPlayer();
    RandomPlayer(string name, int color, Board *board);

    bool makeMove();
};

#endif // H_RANDOM_PLAYER
