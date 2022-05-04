#ifndef H_GAME
#define H_GAME

#include "board.h"
#include "player.h"

class Game {

    public:
        Game();
        void init();
        void changePlayer();

    private:
        void initPlayers();
        void initBoard();
        void paintPoints(vector<Point> &points) const;

        Board board;
        Player playerOne;
        Player playerTwo;
        Player* currentPlayer;
};

#endif // H_GAME
