#include "menuwindow.h"
#include "graphics.h"

#include "windowmanager.h"

MenuWindow::MenuWindow() {}

void MenuWindow::initGraphicElements() {

    line(100, 100, 100, 150);
    line(100, 150, 150, 150);
    line(150, 150, 150, 100);
    line(150, 100, 100, 100);
    outtextxy(110, 110, "BOT");

    line(200, 100, 200, 150);
    line(200, 150, 300, 150);
    line(300, 150, 300, 100);
    line(300, 100, 200, 100);
    outtextxy(210, 110, "Human");
}

int MenuWindow::run() {

    while(true) {
        int x, y;
        do {

            getmouseclick(WM_LBUTTONDOWN, x, y);
        } while(x < 0 || y < 0);

        if(clickedOnBotButton(x, y)) {

            return WindowManager::GAME_WINDOW_BOT;
        }

        if(clickedOnHumanButton(x, y)) {

            return WindowManager::GAME_WINDOW_HUMAN;
        }
    }

    return -2;
}

bool MenuWindow::clickedOnBotButton(int x, int y) {

    return x >= 100 && x <= 150 && y >= 100 && y <= 150;
}

bool MenuWindow::clickedOnHumanButton(int x, int y) {

    return x >= 200 && x <= 250 && y >= 100 && y <= 150;
}
