#ifndef H_WINDOW
#define H_WINDOW

#include "config.h"
#include "graphics.h"

class Window {

    public:
        Window();
        void init();
        void dump();
        int getIdentifier() const;

        virtual int run();
        virtual void initGraphicElements();

    private:
        int identifier;
};

#endif // H_WINDOW
