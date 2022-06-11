#include "windowmanager.h"

#include <iostream>

WindowManager::WindowManager() {

    this->currentWindow = NULL;
}

Window* WindowManager::initWindow(int windowId) {

    if(windowId == MENU_WINDOW) {

        return changeWindow(initMenuWindow());
    }

    return changeWindow(initGameWindow(windowId));
}

Window* WindowManager::changeWindow(Window* nextWindow) {

    if(this->currentWindow != NULL) {

        this->currentWindow->dump();
    }
    this->currentWindow = nextWindow;

    return this->currentWindow;
}

Window* WindowManager::initGameWindow(int windowId) {

    Window* gameWindow;

    if(windowId == GAME_WINDOW_BOT) {

        gameWindow = new GameWindow(MODE::PLAYER_VS_RANDOM);
    }
    else {

        gameWindow = new GameWindow(MODE::TWO_PLAYERS);
    }

    gameWindow->init();

    return gameWindow;
}

Window* WindowManager::initMenuWindow() {

    Window* menuWindow = new MenuWindow();

    menuWindow->init();

    return menuWindow;
}
