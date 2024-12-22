#ifndef Window_H
#define Window_H
#include <ncurses.h>

class Window{
    private:
      WINDOW * win;
      int height=0;
      int width=0;
      int x=0;
      int y=0;
      bool border;
     
    public:
      Window();
      Window(int height, int width, int x, int y, bool border);
      virtual ~Window();
      WINDOW* getWindow();
      int getX();
      int getY();
      int getWidth();
      int getHeight();
      void setWidth(int width);
      void setHeight(int height);
      int resize(int height, int width);
};
#endif