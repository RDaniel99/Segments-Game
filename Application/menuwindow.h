#ifndef H_MENU_WINDOW
#define H_MENU_WINDOW

#include "window.h"

class MenuWindow: public Window {

    public:
        MenuWindow();
        void initGraphicElements();
        int run();

    private:
        bool clickedOnBotButton(int x, int y);
        bool clickedOnHumanButton(int x, int y);
};

#endif // H_MENU_WINDOW
