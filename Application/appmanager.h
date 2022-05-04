#ifndef H_APP_MANAGER
#define H_APP_MANAGER

#include "game.h"
#include "windowmanager.h"

class AppManager {

    public:
        AppManager();
        void run();

    private:
        void initGame();
        void initWindows();

        Game game;
        WindowManager windowManager;
};

#endif // H_APP_MANAGER
