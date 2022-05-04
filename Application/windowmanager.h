#ifndef H_WINDOW_MANAGER
#define H_WINDOW_MANAGER

#include "window.h"

#include <map>

using namespace std;

class WindowManager {

    public:
        WindowManager();
        bool setCurrentWindow(int windowIdentifier);
        void initWindows();

    private:
        int initGameWindow();

        map<int, Window> windows;
        int currentWindowIdentifier;
};

#endif // H_WINDOW_MANAGER
