#ifndef H_WINDOW_MANAGER
#define H_WINDOW_MANAGER

#include "gamewindow.h"
#include "menuwindow.h"

using namespace std;

class WindowManager {

    public:

        static const int MENU_WINDOW = 1;
        static const int GAME_WINDOW_BOT = 2;
        static const int GAME_WINDOW_HUMAN = 3;

        WindowManager();
        Window* initWindow(int windowId);

    private:
        Window* initGameWindow(int windowId);
        Window* initMenuWindow();
        Window* changeWindow(Window* nextWindow);

        Window* currentWindow;
};

#endif // H_WINDOW_MANAGER
