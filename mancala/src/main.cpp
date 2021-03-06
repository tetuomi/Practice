#include <stone.hpp>
#include <dealer.hpp>
#include <display.hpp>
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0);

  Dealer dealer;
  Display display;

  while(true)
    {
      display.show_turn();
      display.show_stones(dealer);
      mvaddch(35 - 10 * display.get_selected(),
              DISPLAY_CENTER - 15 + display.get_turn() * 30,
              '*');
      const auto key{getch()};
      switch(key)
      {
        case KEY_UP:
          display.add_selected();
          break;
        case KEY_DOWN:
          display.subtract_selected();
          break;
      }
      clear();
      if(key == '\n')
      {
        dealer.distribute(display);
        if(dealer.check(display.get_turn())) break;
        display.switch_turn();
      }
    }
  display.show_stones(dealer);
  mvprintw(50, DISPLAY_CENTER, "player%d's win!!!!", display.get_turn() + 1);
  getch();
  endwin();
}
