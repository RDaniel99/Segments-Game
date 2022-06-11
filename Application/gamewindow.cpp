#include "gamewindow.h"

#include <iostream>

GameWindow::GameWindow(MODE gameMode) {

    this->game = Game(gameMode);
}

int GameWindow::run() {

    this->game.init();
    this->game.play();

    return -2;
}
