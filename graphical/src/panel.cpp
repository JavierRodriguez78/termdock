#include "../include/panel.hpp"

#include <ncurses.h>

Panel::Panel(Window win){
    Panel::window= win ;
    Panel::panel = new_panel(win.getWindow());
}

Panel::~Panel(){}

PANEL * Panel::getPanel()
{
    return Panel::panel;
}

void Panel::set_border(int active){
        if (active==1){
            printw("get X %d, get Y %d",window.getX(), window.getY());
            printw("get height %d, get width %d",window.getHeight(), window.getWidth());
            for(int i = window.getX(); i < window.getWidth(); i++){
                //top border
                mvaddch(window.getY(),i,'#');
                //bottom border
                mvaddch(window.getHeight() - 1,i,'#');
            }
            for(int i = window.getY(); i < window.getHeight(); i++){
                //left border
                mvaddch(i,window.getX(),'#');
                //right border
                mvaddch(i,window.getWidth() - 1,'#');
            }
            refresh();
        }
}
