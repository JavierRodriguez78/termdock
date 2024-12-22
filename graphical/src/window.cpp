#include "../include/window.hpp"
  
  Window::Window(){};

  Window::Window(int  height, int width, int x, int y,bool border){
    win = newwin(height,width,x,y);
    Window::x = x;
    Window::y=y;
    Window::height=height;
    Window::width=width;
    Window::border=border;
    refresh();
    if(border){
      box(Window::win, x , y);
    }
    wrefresh(Window::win);
  }

  Window::~Window(){
    delwin(Window::win);
  }

  WINDOW * Window::getWindow(){
       return Window::win;
   }

  int Window::getX(){
    return Window::x;
  }

  int Window::getY(){
    return Window::y;
  }

  int Window::getHeight(){
    return Window::height;
  }

  int Window::getWidth(){
    return Window::width;
  }

void Window::setHeight(int height){
  Window::height = height;
}

int Window::resize(int height, int width){
  int result = wresize(Window::win,height,width);
  wrefresh(Window::win);
  return result;
}