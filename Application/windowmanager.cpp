#include "windowmanager.h"

WindowManager::WindowManager() {

    windows.clear();
    this->currentWindowIdentifier = -2;
}

bool WindowManager::setCurrentWindow(int windowIdentifier) {

    if(this->currentWindowIdentifier != windowIdentifier && windowIdentifier != -2) {

        this->windows[currentWindowIdentifier].dump();
        this->windows[windowIdentifier].init();

        setcurrentwindow(windowIdentifier);

        this->currentWindowIdentifier = windowIdentifier;

        return true;
    }

    return false;
}

void WindowManager::initWindows() {

    int startWindow;
    startWindow = initGameWindow();

    this->setCurrentWindow(startWindow);
}

int WindowManager::initGameWindow() {

    Window gameWindow;

    gameWindow.init();
    gameWindow.dump();

    this->windows[gameWindow.getIdentifier()] = gameWindow;

    return gameWindow.getIdentifier();
}
