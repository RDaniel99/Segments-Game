#include "appmanager.h"

AppManager::AppManager() {}

void AppManager::run() {

    Window* currentWindow = this->windowManager.initWindow(WindowManager::MENU_WINDOW);
    int nextWindow = currentWindow->run();

    while(nextWindow != -2) {

        currentWindow = this->windowManager.initWindow(nextWindow);
        nextWindow = currentWindow->run();
    }
}
