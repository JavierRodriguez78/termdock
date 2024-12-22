#ifndef Terminal_H
#define Terminal_H
#include <ncurses.h>

class Terminal{
    private:
      int height;
      int width;

    public:
      Terminal();
      virtual ~Terminal();
     int getHeight();
     int getWidth();
};
#endif