#ifndef ACTION_HPP
#define ACTION_HPP
#include <vector>
#include <person.hpp>
#include <game_master.hpp>

class Person;
class Master;

class Action {
private:
  std::vector<status> Vstatus;
public:
  Action(const Person& brave,const Person& emperor);
  const std::vector<status>& get_Vstatus() const ;
  void atack(Person& brave,Person& emperor,const Master& master);
  void hp_recovery(Person& person,const Master& master);
  bool judge(const Person& person);
};

#endif
