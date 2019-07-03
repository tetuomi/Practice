#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include "../include/game_master.hpp"
#include <iostream>
#include <ncurses.h>

enum Action{
  ATACK,
  HEAL
};

int main() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0); // 0:invisible

  
  Person emperor(150,5,80),brave(120,3,50);
  Master master;
  while(true) {
    for(int i = 0;i < 11;i++)
      for(int j = 0;j < 12;j++)
        mvaddch(i + 11, j + 1 + 50, AA[i][j]);

    master.show_status(emperor,brave);
    master.show_turn();
    master.show_selection();
    
    const auto buff = getch();
    switch(buff) {
      case KEY_UP:    master.subtract_selected(); break;
      case KEY_DOWN:  master.add_selected();      break;
    }
    clear();    
    if(buff == '\n'){
      if(master.get_turn()){
        switch(master.get_selected()){
          case ATACK:
            brave_atack(emperor,brave);
            master.show_damage(emperor,brave);
            break;
          case HEAL:
            brave.hp_recovery(brave);
            master.show_recovery(brave);
            break;
        }
      }
      else{
        emperor_atack(emperor,brave);
        master.show_damage(emperor,brave);
      }
    }
  }
  endwin();
  return 0;
}
