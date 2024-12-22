#include "../include/terminal.hpp"

Terminal::Terminal(){
   Terminal::width = getmaxx(stdscr);
   Terminal::height = getmaxy(stdscr);
}

Terminal::~Terminal(){}

int Terminal::getHeight(){
  return Terminal::height;
}

int Terminal::getWidth(){
  return Terminal::width;
}