#ifndef H_GAME_WINDOW
#define H_GAME_WINDOW

#include "window.h"
#include "game.h"

class GameWindow: public Window {

public:
    GameWindow(MODE gameMode);
    int run();

    private:
        Game game;
};

#endif // H_GAME_WINDOW
