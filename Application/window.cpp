#include "window.h"

Window::Window() {}

void Window::init() {

    this->identifier = initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    initGraphicElements();
}

void Window::dump() {

    closegraph(this->identifier);
}

int Window::getIdentifier() const {

    return this->identifier;
}

void Window::initGraphicElements() {}

int Window::run() {}
