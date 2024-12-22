#include <iostream>
#include <locale.h>
#include <panel.h>
#include <cstring>
#include "graphical/include/window.hpp"
#include "graphical/include/terminal.hpp"
#include "graphical/include/panel.hpp"

using namespace std;


#ifdef HAVE_SETLOCALE
        (void) setlocale(LC_ALL, "");
#endif



int main()
{	
   initscr(); /* Start Curses Mode*/
   cbreak();	/* Line Bufferin Disabled*/
   noecho();
   
   //Init Terminal
   Terminal terminal;
   
   //Create Window 
   Window Win(
    (int)terminal.getHeight(),
    (int)terminal.getWidth(),
    0,
    0,
    true
    );

   Window winLeft(12,15,5,2,false);
   
   // Create Panel 
   Panel Pan(winLeft);
   Pan.set_border(1);
   refresh();
   getch();
  printw("get resize %d",winLeft.resize(10,10));
   getch();
   Win.~Window();
   Pan.~Panel();
   endwin();
   return 0;
}


