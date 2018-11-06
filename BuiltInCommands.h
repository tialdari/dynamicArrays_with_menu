#ifndef CTABLEMANAGERCOMMANDS_H
#define CTABLEMANAGERCOMMANDS_H

#define DEBUG false


using namespace std;

class Help: public Command{

public:
  Help();
  Help(Menu* menu);
  ~Help();
  bool runCommand();
  //void description();

private:
  Menu* menu;

};



#endif
