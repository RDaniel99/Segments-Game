#include "appmanager.h"

AppManager::AppManager() {

    this->game = Game();
}

void AppManager::run() {

    this->initWindows();
    this->initGame();

    this->game.play();
}

void AppManager::initGame() {

    this->game.init();
}

void AppManager::initWindows() {

    this->windowManager.initWindows();
}
