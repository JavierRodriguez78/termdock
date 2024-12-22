#ifndef Panel_H
#define Panel_H
#include <string>
#include <ncurses.h>
#include <panel.h>
#include "window.hpp"
using namespace std;
class Panel{
    private:
        PANEL * panel;
        int x,y;
    public:
        Window window;
        Panel(Window win);
        virtual ~Panel();
        PANEL * getPanel();
        void set_border(int active);
};
#endif 